cmake_minimum_required(VERSION 3.23)
project(014ClassInherit)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(014ClassInherit
        main.cpp
        class_inherit_basic.cpp
        inherit_mode.cpp
        inherit_obj_model.cpp
        structure_basic_class.cpp
        name_shield_class_scope.cpp
        special_inherit.cpp
        more_and_virtual_inherit.cpp

        )
