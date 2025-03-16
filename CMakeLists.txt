cmake_minimum_required(VERSION 3.30)
project(psm2)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD_REQUIRED 20)

find_package(fmt CONFIG REQUIRED)

include_directories(include)

add_executable(
        psm2
        src/main.cpp
        src/euler.cpp
        src/sava_data.cpp
)
target_link_libraries(
        psm2
        fmt::fmt-header-only
)
