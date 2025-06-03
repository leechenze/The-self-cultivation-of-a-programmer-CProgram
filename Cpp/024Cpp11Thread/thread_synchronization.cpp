//
// Created by Lee ChenZe on 6/3/25.
//
#include <iostream>
#include <thread>
#include <chrono>
#include <unistd.h>
#include <mutex>
// 原生线程库
#include <pthread.h>

using namespace std;


void thread_synchronization_mutex();
void thread_synchronization_conditional_variable();
void thread_synchronization_producer_consumer();

void thread_synchronization() {
    // cout << endl << "========================thread_synchronization========================" << endl;
    // cout << endl << "========================thread_synchronization========================" << endl;

    /** 互斥锁 */
    // thread_synchronization_mutex();
    /** 条件变量 */
    // thread_synchronization_conditional_variable();
    /** 生产者/消费者模型 */
    thread_synchronization_producer_consumer();

}
