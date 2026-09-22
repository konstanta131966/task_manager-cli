#include "../include/Task.hpp" 

std:: string priority_to_string(Priority priority){
    switch (priority) {
        case Priority :: Low:
            return "Low";
        case Priority :: Medium:
            return "Medium";
        case Priority :: High:
            return "High";
    }return "Unknown";
};

Priority string_to_priority(std::string_view str){
    if (str == "Low")
        return Priority :: Low;
    
    if (str == "Medium")
        return Priority :: Medium;
    
    if (str == "High")
        return Priority :: High;

    return Priority :: Low; //temporary will change to uncategorized or something like that
};
