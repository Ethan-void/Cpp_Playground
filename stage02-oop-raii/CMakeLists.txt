cmake_minimum_required(VERSION 3.10)
project(stage02_oop_raii)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(stage02_oop_raii
    main.cpp
    Robot.cpp
    RobotManager.cpp
)

target_include_directories(stage02_oop_raii PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

