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

void this_thread_global_function() {
    cout << endl << "========================this_thread_global_function========================" << endl;

    // 用普通函数创建线程。
    thread t1(func2, 3, "我是一只傻傻鸟。");
    thread t2(func2, 8, "我有一只小小鸟。");
    // 注意t2通过move转为右值之后就变成了一个空的线程对象，move(t2)之后不能再用t2了
    thread t3(move(t2));

    cout << "主线程ID = " << this_thread::get_id() << endl;

    // cout << "子线程t1ID = " << t1.get_id() << endl;
    // cout << "子线程t2ID = " << t2.get_id() << endl;
    // 交换t1和t2;
    // t1.swap(t2);
    // cout << "子线程t1ID = " << t1.get_id() << endl;
    // cout << "子线程t2ID = " << t2.get_id() << endl;

    t1.join();
    // t2.join();
    t3.join();



    cout << endl << "========================this_thread_global_function========================" << endl;
}
