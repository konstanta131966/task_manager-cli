#include "../include/TaskManager.hpp"
#include "../include/Task.hpp"
#include <algorithm>
#include <string>
#include <vector>
#include <cstddef>
#include <iostream>

void TaskManager:: add_task(std::string description,Priority priority){
    tasks.push_back(Task{
        .id = next_id++,
        .description = std::move(description),
        .priority = priority,
        .is_completed = false
    });
}

void TaskManager :: list_tasks() const {
    if (tasks.empty()){
        std::cout << "No tasks found. \n";
        return;
    }
    std::cout << "\n--- Task List ---\n";
    for (const auto& task : tasks ){
        std :: cout << "~Task ID:" << task.id << "\n";
        std :: cout <<"~Task description: " << task.description << "\n";
        std :: cout <<"~Task Priority: " << priority_to_string(task.priority) << "\n";
        std :: cout <<"~Task completed: " <<( task.is_completed ? "[X]" : "[ ]") << "\n";
    }
    std :: cout << "----------------------------\n";


}

bool TaskManager :: mark_completed(std::size_t id){
    auto it = std :: find_if(tasks.begin(),tasks.end(), [id](const Task& t){
        return t.id == id;});
    if(it != tasks.end()){
        it -> is_completed = true;
        return true;
    }
    return false;
}


bool TaskManager::remove_task(std::size_t id) {
    auto removed_count = std::erase_if(tasks, [id](const Task& t) {
        return t.id == id;
    });

    return removed_count > 0;
}