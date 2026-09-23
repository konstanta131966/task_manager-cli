#include <catch2/catch_test_macros.hpp>
#include "TaskManager.hpp"
#include "Task.hpp"
#include <filesystem>


TEST_CASE("Priority string parsing works case-insensitively", "[task]"){
    REQUIRE(string_to_priority("high") == Priority::High);
    REQUIRE(string_to_priority("HIGH") == Priority::High);
    REQUIRE(string_to_priority("Medium") == Priority :: Medium);
    REQUIRE(string_to_priority("low") == Priority :: Low);
    REQUIRE(string_to_priority("ofghdr") == Priority :: Low);
}

TEST_CASE("TaskManager CRUD operations", "[manager]"){
    TaskManager manager;

    SECTION("Adding tasks increments ID properly"){
        manager.add_task("First task", Priority :: Low);
        manager.add_task("Second task", Priority :: High);

        REQUIRE(manager.mark_completed(1) == true);
        REQUIRE(manager.mark_completed(2) == true);

        REQUIRE(manager.mark_completed(432) == false);
    }

    SECTION("Removing a task behaves correctly"){
        manager.add_task("Task to delete", Priority :: Medium);

        REQUIRE(manager.remove_task(1) == true);
        REQUIRE(manager.remove_task(1) == false); //alreadyremoved
    }
}

TEST_CASE("Sorting algorithms order tasks correctly","[manager][sorting]"){
    TaskManager manager;
    manager.add_task("Low prio task", Priority:: Low);
    manager.add_task("High prio task", Priority :: High);
    manager.add_task("Medium prio task", Priority :: Medium);

    SECTION("Sort by priority orders High,Medium,Low"){
        manager.sort_by_priority();
        const auto& tasks = manager.get_tasks();

        REQUIRE(tasks.size() == 3);
        REQUIRE(tasks[0].priority == Priority :: High);
        REQUIRE(tasks[1].priority == Priority :: Medium);
        REQUIRE(tasks[2].priority == Priority :: Low);
    }

    SECTION("Sort by status places incomplete tasks first"){
        manager.mark_completed(2);

        manager.sort_by_status();
        const auto& tasks = manager.get_tasks();

        REQUIRE(tasks.size() == 3);
        REQUIRE(tasks[0].is_completed == false);
        REQUIRE(tasks[1].is_completed == false);
        REQUIRE(tasks[2].is_completed == true);
    }

}
TEST_CASE("CSV Persistence cycle works end-to-end", "[manager][persistence]") {
    const std::string test_file = "test_tasks.csv";
    
    // Clean up any stale test file from a previous run
    std::filesystem::remove(test_file);

    {
        TaskManager manager;
        manager.add_task("Persistent Task 1", Priority::High);
        manager.add_task("Persistent Task 2", Priority::Low);
        manager.mark_completed(1);

        REQUIRE(manager.save_to_file(test_file) == true);
    }

    {
        TaskManager loaded_manager;
        REQUIRE(loaded_manager.load_from_file(test_file) == true);

        const auto& tasks = loaded_manager.get_tasks();
        REQUIRE(tasks.size() == 2);

        
        REQUIRE(tasks[0].id == 1);
        REQUIRE(tasks[0].description == "Persistent Task 1");
        REQUIRE(tasks[0].priority == Priority::High);
        REQUIRE(tasks[0].is_completed == true);

        // Verify ID counter was updated after loading
        loaded_manager.add_task("Persistent Task 3", Priority::Medium);
        REQUIRE(loaded_manager.get_tasks().back().id == 3);
    }

    // Clean up after test completes
    std::filesystem::remove(test_file);
}