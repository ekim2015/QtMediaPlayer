# must ensure that CMake is at least version 
cmake_minimum_required(VERSION 3.16)

project(media_player VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# get Qt package
find_package(Qt6 REQUIRED COMPONENTS Widgets Core)

qt_standard_project_setup()

add_subdirectory(src/player)




