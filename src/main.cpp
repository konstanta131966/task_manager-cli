#include <iostream>
#include "../include/Task.hpp"
#include "../include/TaskManager.hpp"

int main(){
    /*Task task{
        .id = 1,
        .description = "Learn c++20 designated initializers",
        .priority = Priority :: Medium,
        .is_completed = false 
    
    };


std::cout << "Task #" << task.id << ": " << task.description << '\n';
std::cout << "Priority: " << priority_to_string(task.priority) << '\n';
std::cout << "Done : " << (task.is_completed ? "Yes" : "No") << '\n';
*/
    TaskManager manager;

    manager.add_task("Finish Step 2 of CLI project", Priority::High);
    manager.add_task("Go to the gym", Priority :: High);
    manager.add_task("Read a book", Priority :: Medium);

    std::cout << "Initial list:";
    manager.list_tasks();

    std::cout << "\nMarking task #1 complete ...\n";
    manager.mark_completed(1);

    std::cout << "\nRemoving task #2 ...\n";

    std::cout <<"\nUpdated list:";
    manager.list_tasks();

    return 0;
};