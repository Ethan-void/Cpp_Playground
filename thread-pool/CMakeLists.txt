# 1. 规定 CMake 的最低版本（防止版本太老不支持新特性）
cmake_minimum_required(VERSION 3.10)

# 2. 给你的项目起个名字
project(RobotDemo)

# 3. 设置 C++ 标准（比如用 C++17）
set(CMAKE_CXX_STANDARD 17)

# 4. 最关键的一句：生成可执行文件
# 格式：add_executable(生成的程序名 源文件1 源文件2 ...)
add_executable(my_app main.cpp)