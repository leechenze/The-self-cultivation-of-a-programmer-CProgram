//
// Created by Lee ChenZe on 6/1/25.
//
#include <stdio.h>
#include <iostream>
#include <string>
#include <typeinfo>

using namespace std;

void create_thread();
void reclaiming_thread_resource();
void this_thread_global_function();
void call_once_function();

int main() {
    /** =========创建线程(create_thread)========= */
    create_thread();
    /** =========线程资源的回收(reclaiming_thread_resource)========= */
    reclaiming_thread_resource();
    /** =========this_thread的全局函数(this_thread_global_function)========= */
    this_thread_global_function();
    /** =========call_once函数(call_once_function)========= */
    call_once_function();



};

