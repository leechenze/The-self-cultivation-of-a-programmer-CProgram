cmake_minimum_required(VERSION 3.23)
project(017ClassTemplate)

set(CMAKE_CXX_STANDARD 14)

add_executable(017ClassTemplate
        main.cpp
        class_template_basic.cpp
        template_class_stack.cpp
        template_class_array.cpp
        joint_and_recursive_use_of_templates.cpp
        template_class_specific.cpp
        template_class_inherit.cpp
        template_class_func.cpp
        template_class_friendship.cpp
        member_template_class.cpp
        params_template_class.cpp

        )
