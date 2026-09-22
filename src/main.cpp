#include <iostream>
#include "../include/Task.hpp"

int main(){
    Task task{
        .id = 1,
        .description = "Learn c++20 designated initializers",
        .priority = Priority :: Medium,
        .is_completed = false 
    
    };


std::cout << "Task #" << task.id << ": " << task.description << '\n';
std::cout << "Priority: " << priority_to_string(task.priority) << '\n';
std::cout << "Done : " << (task.is_completed ? "Yes" : "No") << '\n';

return 0;
};