cmake_minimum_required(VERSION 3.30)
project(psm2)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 20)

include_directories(include)

add_executable(
        psm2
        src/main.cpp
        src/euler.cpp
        src/save_data.cpp
)

