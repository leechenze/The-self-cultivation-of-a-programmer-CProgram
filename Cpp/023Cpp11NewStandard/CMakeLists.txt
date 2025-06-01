cmake_minimum_required(VERSION 3.23)
project(023Cpp11NewStandard)

set(CMAKE_CXX_STANDARD 14)

add_executable(023Cpp11NewStandard
        main.cpp
        cpp_new_standard.cpp
        delegate_construction_and_inheritance_construction.cpp
        lambda_func.cpp
        r_value_references.cpp
        move_semantics.cpp
        perfect_forwarding.cpp
        variadic_templates.cpp
        chrono_time_operation_library.cpp




        )
