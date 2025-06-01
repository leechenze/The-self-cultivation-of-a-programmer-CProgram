//
// Created by Lee ChenZe on 6/1/25.
//
#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

// 普通函数。
void func1(int bh, const string& str) {
    for (int ii = 1; ii <= 10; ii++)
    {
        cout << "第" << ii << "次表白：亲爱的" << bh << "号，" << str << endl;
        this_thread::sleep_for(chrono::seconds(1));   // 休眠1秒。
    }
}

void reclaiming_thread_resource() {
    cout << endl << "========================reclaiming_thread_resource========================" << endl;

    // // 用普通函数创建线程。
    // thread t1(func1, 3, "我是一只傻傻鸟。");
    // thread t2(func1, 8, "我有一只小小鸟。");

    // // 分离子线程。
    // t1.detach();
    // t2.detach();

    // // cout << "任务开始。\n";
    // for (int ii = 0; ii < 12; ii++) {
    // 	cout << "执行任务中......\n";
    //     this_thread::sleep_for(chrono::seconds(1));   // 假设执行任务需要时间。
    // }
    // // cout << "任务完成。\n";

    //t1.join();         // 回收线程t1的资源。
    //t2.join();         // 回收线程t2的资源。

    // 这是主线程等待12秒的原因是 值线程需要有大概10秒的循环要运行
    // this_thread::sleep_for(chrono::seconds(12));


    cout << endl << "========================reclaiming_thread_resource========================" << endl;
}
