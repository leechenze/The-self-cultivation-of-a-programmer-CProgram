cmake_minimum_required(VERSION 3.23)
project(024Cpp11Thread)

set(CMAKE_CXX_STANDARD 14)

add_executable(024Cpp11Thread
        main.cpp
        create_thread.cpp
        reclaiming_thread_resource.cpp
        this_thread_global_function.cpp
        call_once_function.cpp
        native_handle_function.cpp
        thread_safe.cpp
        thread_synchronization.cpp
        thread_synchronization_mutex.cpp
        thread_synchronization_conditional_variable.cpp
        thread_synchronization_producer_consumer.cpp
        atomic_type.cpp

        )
