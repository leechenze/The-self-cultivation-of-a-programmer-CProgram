cmake_minimum_required(VERSION 3.23)
project(019STLContainer_Algorithm)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(019STLContainer_Algorithm
        main.cpp
        string_container.cpp
        vector_container.cpp
        cus_iterator.cpp
        range_for_loop.cpp
        list_container.cpp
        key_value_pair.cpp
        map_container.cpp
        unordered_map_container.cpp

        )

