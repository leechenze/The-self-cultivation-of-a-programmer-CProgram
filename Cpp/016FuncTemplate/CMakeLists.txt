cmake_minimum_required(VERSION 3.23)
project(016FuncTemplate)

set(CMAKE_CXX_STANDARD 14)

add_executable(016FuncTemplate
        main.cpp
        auto_deduce_type.cpp
        func_template_basic.cpp
        func_template_precautions.cpp
        func_template_specific.cpp
        func_template_advanced.cpp

        )
