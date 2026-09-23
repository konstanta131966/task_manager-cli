#include "../include/Task.hpp" 
#include <cctype>
#include <string>
#include <algorithm>

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

//internal helper
std :: string to_upper(std::string str){
    std :: transform(str.begin(),str.end(),str.begin(),[](unsigned char c){
        return static_cast<char>(std :: toupper(c));
    });
    return str;
}

Priority string_to_priority(std::string_view str){
   std :: string upper_str = to_upper(std::string {str});
   
   if (upper_str == "HIGH") return Priority::High;
   if (upper_str == "MEDIUM") return Priority :: Medium;
   return Priority :: Low; //default fallback
};


