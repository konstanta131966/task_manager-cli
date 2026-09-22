#include "../include/TaskManager.hpp"
#include "../include/Task.hpp"
#include <algorithm>
#include <sstream>
#include <string>
#include <sys/types.h>
#include <vector>
#include <cstddef>
#include <iostream>
#include <fstream>


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
    auto original_size = tasks.size();
    tasks.erase(
        std::remove_if(tasks.begin(),tasks.end(),[id](const Task& t){
            return t.id == id;
        }),
        tasks.end()
    );
    return tasks.size() < original_size;
}

bool TaskManager :: save_to_file(const std:: string& filename)const{
    std :: ofstream file(filename);  //open for writing
    if(!file.is_open()) return false;
    for (const auto& task : tasks){
        file <<  task.id << ","
             <<  task.description << ","
             <<  priority_to_string(task.priority) << ","
             <<  (task.is_completed ? "1" : "0") << "\n" ; 
    }
    return true;
}

bool TaskManager :: load_from_file(const std::string &filename){
    std :: ifstream file(filename); //open for reading
    if(!file.is_open()) return false;
    tasks.clear(); //clear slate so we don't accumulate duplicates
    std :: size_t max_id = 0; 
    std :: string line;
    while (std :: getline(file,line)){
        if(line.empty()) continue;

        std :: stringstream ss(line);

        std :: string id_str;
        std :: string desc;
        std :: string priority_str;
        std :: string completed_str;

        std :: getline(ss, id_str, ',');
        std :: getline(ss, desc, ',');
        std :: getline(ss , priority_str,',');
        std :: getline(ss, completed_str, ',');

        Task task{
            .id = std :: stoul(id_str),
            .description = desc,
            .priority = string_to_priority(priority_str),
            .is_completed = (completed_str == "1")

        };

        tasks.push_back(task);
        
        max_id = std :: max(max_id,task.id);
    }
    next_id = max_id + 1;
    return true;
}