cmake_minimum_required(VERSION 3.23)
project(013Operator)

set(CMAKE_CXX_STANDARD 14)

add_executable(013Operator
        main.cpp
        operator_basic.cpp
        overloading_relational_operators.cpp
        overloading_left_shift_operators.cpp
        overloading_subscript_operators.cpp
        overloading_assignment_operators.cpp
        overloading_new_del_operators.cpp
        simple_memory_pool.cpp
        overloading_parenthesis_operators.cpp
        overloading_unary_operators.cpp
        auto_type_conversion.cpp
        conversion_func.cpp

        )
