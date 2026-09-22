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

        bool save_to_file(const std:: string& filename)const;
        bool load_from_file(const std:: string& filename);
};