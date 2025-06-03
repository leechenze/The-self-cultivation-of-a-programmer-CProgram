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
atomic<int> aa1;

// 普通函数，把全局变量aa加1000000次。
void func7() {
    for (int ii = 1; ii <= 1000000; ii++)
        aa1++;
}

void atomic_type() {
    cout << endl << "========================atomic_type========================" << endl;

    // 正常执行func函数两次，会得到正常的两百万
    // func7();
    // func7();
    // 用普通函数创建线程，永远都不会得到正常的两百万，
    thread t1(func7);     // 创建线程t1，把全局变量aa1加1000000次。
    thread t2(func7);     // 创建线程t2，把全局变量aa1加1000000次。

    t1.join();         // 回收线程t1的资源。
    t2.join();         // 回收线程t2的资源。

    cout << "aa1=" << aa1 << endl;   // 显示全局变量aa的值。

    cout << endl << "========================其他常用方法========================" << endl;

    atomic<int> a2;
    a2.store(3);
    cout << "a2 = " << a2.load() << endl;

    a2.fetch_add(5);
    cout << "a2.load() = " << a2.load() << endl;
    a2.fetch_sub(3);
    cout << "a2.load() = " << a2.load() << endl;


    cout << endl << "========================atomic_type========================" << endl;
}
