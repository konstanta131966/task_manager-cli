#pragma once

#include <iostream>



    enum class Priority{
        Low,
        Medium,
        High
    };

    struct Task{
        std:: size_t id ;
        std:: string description;
        Priority priority; 
        bool is_completed{false}; //giving it a default value

    };

    //helper functions
    std:: string priority_to_string(Priority priority);

    Priority string_to_priority(std::string_view str);
    //using string_view avoids unnecessary string allocations when passing string literals or tokens

