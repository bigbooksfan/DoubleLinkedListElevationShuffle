cmake_minimum_required(VERSION 3.28)
project(Lists_project)

set(CMAKE_CXX_STANDARD 20)

set(FILES
    src/source.cpp
    src/single_linked_list.h
    src/single_linked_list.cpp
)

add_executable(Lists ${FILES})