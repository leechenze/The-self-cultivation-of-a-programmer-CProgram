cmake_minimum_required(VERSION 3.23)
project(005fundamentalsOfFunc)

set(CMAKE_CXX_STANDARD 14)

include_directories(moreFunc)
include_directories(tools)

add_executable(005fundamentalsOfFunc
        moreFunc/funcs.cpp
        moreFunc/funcs.hpp
        tools/tools.cpp
        tools/tools.hpp
        main.cpp)
