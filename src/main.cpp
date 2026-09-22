#include <ios>
#include <iostream>
#include "../include/Task.hpp"
#include "../include/TaskManager.hpp"
#include <limits>

int main(){

    const std :: string filename = "tasks.csv";
    TaskManager manager;

    if (!manager.load_from_file(filename)){
        std :: cout << "No previous data found. Starting with a fresh task list.\n";
    }
    else{
        std :: cout << "Successfullu loaded existing tasks from " << filename << ".\n";
    }

    bool running = true;
    
    while(running){
        std::cout << "\n--- Task Manager ---\n"
                  << "1. List Tasks\n"
                  << "2. Add Task\n"
                  << "3. Mark Task Complete\n"
                  << "4. Delete Task\n"
                  << "5. Sort by Priority\n"
                  << "6. Sort by Status\n"
                  << "7. Clear all Tasks \n"
                  << "8. Save & Exit\n"
                  << "Choose an option: ";
        
        int choice{0};
        if (!(std::cin >> choice)){
            //handling non-numeric input
            std::cout << "Invalid input. Please enter a number from the menu.\n";
            std::cin.clear();
            std :: cin.ignore(std ::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        switch (choice) {
            case 1 : 
                manager.list_tasks();    
                break;
            case 2:{
                std :: string description,priority;
                std :: cout << "Enter description of the task you wish to add: \n";
                std :: getline(std::cin,description);
                std :: cout << "\nEnter the priority of the task: \n";
                std :: getline(std::cin,priority);
                manager.add_task(description,string_to_priority(priority));
                break;
            }
            case 3:{
                int id;
                std :: cout << "Enter the ID of the task: ";
                if (!(std::cin>>id)){
                    std::cout << "Invalid input. Please enter a valid ID.\n";
                    std ::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    continue;
                }
                if(manager.mark_completed(id)){
                    std::cout << "Task #" << id << " marked as complete.\n";
                }
                else{
                    std::cout << "Task #" << id << " not found.\n";
                }
                break;
            }
            case 4:{
                int id;
                std :: cout << "Enter the ID of the task you wish to delete: ";
                if (!(std::cin >> id)){
                    std::cout << "Invalid input. Please enter a valid ID. \n";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                    continue;
                }
                if(manager.remove_task(id)){
                    std::cout << "Task #" << id << " removed.\n";
                }
                else{
                    std::cout << "Task #" << id << " not found.\n";
                }
                break;
            }
            case 5:
                manager.sort_by_priority();
                std::cout << "Tasks sorted by priority.\n";
                break;
            case 6:
                manager.sort_by_status();
                std::cout << "Tasks sorted by status.\n";
                break;
            case 7:{
                char confirm{'n'};
                std :: cout << "Are you sure you want to clear all tasks (y/n): ";
                std::cin >> confirm;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

                if (confirm == 'y'){
                    manager.clear_all();
                    std::cout << "All tasks have been cleared. \n";
                }
                else{
                    std::cout << "Action cancelled.\n";
                }
                break;
            }

            case 8:
                manager.save_to_file(filename);
                running = false; //exiting the loop
                break;
            default:
                std :: cout << "Invalid choice. Please select 1-7\n";
                break; //back to the menu
        }
    }
    return 0;
}






 


