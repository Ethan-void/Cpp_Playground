cmake_minimum_required(VERSION 3.10)
project(stage07_concurrency)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(stage07_concurrency main.cpp)

find_package(Threads REQUIRED)
target_link_libraries(stage07_concurrency PRIVATE Threads::Threads)

