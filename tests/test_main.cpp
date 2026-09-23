#include <catch2/catch_test_macros.hpp>
#include "TaskManager.hpp"
#include "Task.hpp"


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