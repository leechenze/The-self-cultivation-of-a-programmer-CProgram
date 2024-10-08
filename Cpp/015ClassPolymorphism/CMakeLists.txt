cmake_minimum_required(VERSION 3.23)
project(015ClassPolymorphism)

set(CMAKE_CXX_STANDARD 14)

add_executable(015ClassPolymorphism
        main.cpp
        polymorphism_base_concept.cpp
        polymorphism_application_scenario.cpp
        polymorphism_obj_model.cpp
        destruct_derived_classes.cpp
        pure_virtual_func_abstract_class.cpp
        run_phase_type_identification.cpp
        typeid_and_typeinfoclass.cpp

        )
