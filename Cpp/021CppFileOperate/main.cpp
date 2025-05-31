//
// Created by Lee ChenZe on 5/30/25.
//
#include <stdio.h>
#include <iostream>
#include <string>
#include <typeinfo>

using namespace std;

void write_text_file();
void read_text_file();
void write_binary_file();
void read_binary_file();
void random_access();
void file_buffer_and_stream_status();

int main() {
    /** =========写入文本文件(write_text_file)========= */
    write_text_file();
    /** =========读取文本文件(write_text_file)========= */
    read_text_file();
    /** =========写入二进制文件(write_binary_file)========= */
    write_binary_file();
    /** =========读取二进制文件(read_binary_file)========= */
    read_binary_file();
    /** =========随机存取(random_access)========= */
    random_access();
    /** =========文件缓冲区和流状态(file_buffer_and_stream_status)========= */
    file_buffer_and_stream_status();



};

