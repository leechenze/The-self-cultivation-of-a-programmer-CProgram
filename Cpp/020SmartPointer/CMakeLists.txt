cmake_minimum_required(VERSION 3.23)
project(020SmartPointer)

set(CMAKE_CXX_STANDARD 14)

add_executable(020SmartPointer
        main.cpp
        smart_pointer_unique_ptr.cpp
        smart_pointer_shared_ptr.cpp
        smart_pointer_remover.cpp
        smart_pointer_weak_ptr.cpp




        )
