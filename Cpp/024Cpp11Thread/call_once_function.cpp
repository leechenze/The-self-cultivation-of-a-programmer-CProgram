//
// Created by Lee ChenZe on 6/1/25.
//
#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

// 普通函数。
void func2(int bh, const string& str) {
    cout << "子线程ID = " << this_thread::get_id() << endl;
    for (int ii = 1; ii <= 10; ii++)
    {
        cout << "第" << ii << "次表白：亲爱的" << bh << "号，" << str << endl;
        this_thread::sleep_for(chrono::seconds(1));   // 休眠1秒。
    }
}

void call_once_function() {
    cout << endl << "========================call_once_function========================" << endl;

    // 用普通函数创建线程。
    thread t1(func2, 3, "我是一只傻傻鸟。");
    thread t2(func2, 8, "我有一只小小鸟。");

    // TODO

    cout << endl << "========================call_once_function========================" << endl;
}
