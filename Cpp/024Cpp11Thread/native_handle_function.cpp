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

void func() {
    for(int i = 1; i < 10; i++) {
        cout << "i = " << i << endl;
        sleep(1);
    }
}

void native_handle_function() {
    cout << endl << "========================native_handle_function========================" << endl;

    // 用普通函数创建线程
    thread t1(func);

    // 为了演示效果，在这里休眠五秒，即在五秒之后停止线程
    sleep(5);

    // 获取linux原生的线程句柄
    pthread_t thid = t1.native_handle();
    // 取消线程
    pthread_cancel(thid);

    t1.join();

    cout << endl << "========================native_handle_function========================" << endl;
}
