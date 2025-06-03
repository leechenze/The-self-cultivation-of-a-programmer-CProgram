//
// Created by Lee ChenZe on 6/1/25.
//
#include <iostream>
#include <thread>
#include <chrono>
#include <unistd.h>
#include <mutex>


using namespace std;


// 定义onceFlag全局变量，本质是取值为0和1的锁。
once_flag onceFlag;

// 在线程中打算只调用一次的函数
void once_func(int bh, const string &str) {
    cout << "once_func() bh = " << bh << ", str = " << str << endl;
}

// 普通函数。
void func3(int bh, const string& str) {
    // once_func(0, "各位观众，我要开始表白了");
    call_once(onceFlag, once_func, 0, "各位观众，我要开始表白了");
    cout << "子线程ID = " << this_thread::get_id() << endl;
    for (int ii = 1; ii <= 10; ii++)
    {
        cout << "第" << ii << "次表白：亲爱的" << bh << "号，" << str << endl;
        // 休眠1秒。
        sleep(1);
    }
}

void call_once_function() {
    cout << endl << "========================call_once_function========================" << endl;

    // 用普通函数创建线程。
    thread t8(func3, 3, "I'm leonardo");
    thread t9(func3, 8, "I'm hamilton");

    t8.join();
    t9.join();

    cout << endl << "========================call_once_function========================" << endl;
}
