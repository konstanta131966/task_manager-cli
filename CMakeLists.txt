cmake_minimum_required(VERSION 3.20)
project(TaskManager VERSION 1.0 LANGUAGES CXX)

add_executable(task_manager
    src/main.cpp
    src/Task.cpp    
)

target_compile_features(task_manager PRIVATE cxx_std_20)
target_include_directories(task_manager PRIVATE include)
