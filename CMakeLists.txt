cmake_minimum_required(VERSION 3.30)
project(psm2)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 20)

include_directories(include)

find_package(Python3 REQUIRED)

add_executable(
        psm2
        src/main.cpp
        src/euler.cpp
        src/save_data.cpp
)

add_custom_command(
        TARGET psm2 POST_BUILD
        COMMAND $<TARGET_FILE:psm2>
        COMMAND ${Python3_EXECUTABLE} ${CMAKE_SOURCE_DIR}/src/viz.py
)
