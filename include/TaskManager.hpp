#pragma once

#include "Task.hpp"
#include <vector>
#include <string>
#include <cstddef>

class TaskManager{
    private:
        std::vector<Task> tasks;
        std::size_t next_id{1};

    public:
        void add_task(std::string description,Priority priority);
        void list_tasks() const;

        bool mark_completed(std::size_t id);
        bool remove_task(std :: size_t id);

        //file I/O with CSV 
        bool save_to_file(const std:: string& filename)const;
        bool load_from_file(const std:: string& filename);

        //sorting (standard algorithms)
        void sort_by_priority();
        void sort_by_status();

        //clears all saved tasks.
        void clear_all();
        //getter (for testing)
        const std::vector<Task>& get_tasks() const { return tasks;}
};