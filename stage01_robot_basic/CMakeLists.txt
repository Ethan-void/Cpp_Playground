cmake_minimum_required(VERSION 3.10)
project(stage01_robot_basic)

# 设置 C++ 标准，CLI11 需要至少 C++11，推荐 17
set(CMAKE_CXX_STANDARD 17)

# 显式列出源文件
add_executable(my_bot 
    main.cc 
    Robot.cc 
    SpecialRobots.cc 
    Systems.cc
)

# 告诉 CMake 头文件就在当前目录下
target_include_directories(my_bot PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})