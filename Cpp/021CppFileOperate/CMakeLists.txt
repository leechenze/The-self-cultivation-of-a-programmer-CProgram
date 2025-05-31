cmake_minimum_required(VERSION 3.23)
project(021CppFileOperate)

set(CMAKE_CXX_STANDARD 14)

add_executable(021CppFileOperate
        main.cpp
        write_text_file.cpp
        read_text_file.cpp
        write_binary_file.cpp
        read_binary_file.cpp
        random_access.cpp
        file_buffer_and_stream_status.cpp


        )
