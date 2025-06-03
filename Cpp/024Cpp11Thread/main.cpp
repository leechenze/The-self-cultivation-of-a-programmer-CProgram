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
void native_handle_function();
// void thread_safe();
void thread_synchronization();
void atomic_type();

int main() {
    /** =========创建线程(create_thread)========= */
    // create_thread();
    /** =========线程资源的回收(reclaiming_thread_resource)========= */
    // reclaiming_thread_resource();
    /** =========this_thread的全局函数(this_thread_global_function)========= */
    // this_thread_global_function();
    /** =========call_once函数(call_once_function)========= */
    // call_once_function();
    /** =========native_handle函数(native_handle_function)========= */
    // native_handle_function();
    /** =========线程安全(thread_safe)========= */
    // thread_safe();
    /** =========线程同步/互斥锁(thread_synchronization)========= */
    // thread_synchronization();
    /** =========原子类型atomic(atomic_type)========= */
    atomic_type();




};

