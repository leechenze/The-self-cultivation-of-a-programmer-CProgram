cmake_minimum_required(VERSION 3.23)
project(018CompileLinkNamingSapce)

set(CMAKE_CXX_STANDARD 14)

add_executable(
        018CompileLinkNamingSapce
        main.cpp
        compile_processing_public.h
        compile_processing_public.cpp

        compile_processing.cpp
        naming_space.cpp
        type_trans_static_cast.cpp
        
)
