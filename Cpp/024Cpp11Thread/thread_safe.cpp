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

// 定义全局变量，用volatile关键字修饰
volatile int aa = 0;

// 普通函数，把全局变量aa加1000000次。
void func4() {
    for (int ii = 1; ii <= 1000000; ii++)
        aa++;
}

void thread_safe() {
    cout << endl << "========================thread_safe========================" << endl;

    // 正常执行func函数两次，会得到正常的两百万
    // func4();
    // func4();
    // 用普通函数创建线程，永远都不会得到正常的两百万，
    thread t1(func4);     // 创建线程t1，把全局变量aa加1000000次。
    thread t2(func4);     // 创建线程t2，把全局变量aa加1000000次。

    t1.join();         // 回收线程t1的资源。
    t2.join();         // 回收线程t2的资源。

    cout << "aa=" << aa << endl;   // 显示全局变量aa的值。

    cout << endl << "========================thread_safe========================" << endl;
}
