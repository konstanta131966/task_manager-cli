cmake_minimum_required(VERSION 3.20)
project(TaskManager VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#1. Core Logic Library
add_library(task_manager_core
    src/Task.cpp
    src/TaskManager.cpp
)
target_include_directories(task_manager_core PUBLIC include)

#2 Main CLI executable
add_executable(task_manager src/main.cpp)
target_link_libraries(task_manager PRIVATE task_manager_core)

#3 Unit Testing
include(CTest)
include(FetchContent)

FetchContent_Declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG v3.5.2
)
FetchContent_MakeAvailable(Catch2)

#4 Test executable
add_executable(task_tests tests/test_main.cpp)
target_link_libraries(task_tests PRIVATE task_manager_core Catch2::Catch2WithMain)

#Register with CTest
add_test(NAME AllTests COMMAND task_tests)





