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


// 创建互斥锁，保护共享资源cout对象。
mutex mtx;
int bb = 0;

// 普通函数。
void func5(int bh, const string &str) {
    for (int ii = 1; ii <= 10; ii++) {
        mtx.lock();      // 申请加锁。
        cout << "第" << ii << "次表白：亲爱的" << bh << "号，" << str << endl;
        mtx.unlock();  // 解锁。
        // 休眠1秒。
        sleep(1);
    }
}

// 普通函数，把全局变量aa加1000000次。
void func6() {
    for (int ii = 1; ii <= 1000000; ii++){
        lock_guard<mutex> mlock(mtx);
        // mtx.lock();
        bb++;
        // mtx.unlock();
    }
}

class AA
{
    recursive_mutex m_mutex;
public:
    void func1() {
        m_mutex.lock();
        cout << "调用了func1()\n";
        m_mutex.unlock();
    }

    void func2() {
        m_mutex.lock();
        cout << "调用了func2()\n";
        func1();
        m_mutex.unlock();
    }
};

void thread_synchronization_mutex(){

    cout << endl << "========================thread_synchronization_mutex========================" << endl;


    // // 用普通函数创建线程。
    // thread t1(func5, 1, "I'm leonardo");
    // thread t2(func5, 2, "I'm bryant");
    // thread t3(func5, 3, "I'm abraham");
    // thread t4(func5, 4, "I'm beckham");
    // thread t5(func5, 5, "I'm hamilton");
    //
    // t1.join();         // 回收线程t1的资源。
    // t2.join();         // 回收线程t2的资源。
    // t3.join();         // 回收线程t3的资源。
    // t4.join();         // 回收线程t4的资源。
    // t5.join();         // 回收线程t5的资源。

    cout << endl << "========================recursive_mutex========================" << endl;

    // AA aa;
    // // aa.func1();
    // aa.func2();

    cout << endl << "========================lock_guard========================" << endl;

    // 正常执行func函数两次，会得到正常的两百万
    // func6();
    // func6();
    // 用普通函数创建线程，永远都不会得到正常的两百万，
    // thread t1(func6);     // 创建线程t1，把全局变量aa加1000000次。
    // thread t2(func6);     // 创建线程t2，把全局变量aa加1000000次。
    //
    // t1.join();         // 回收线程t1的资源。
    // t2.join();         // 回收线程t2的资源。
    //
    // cout << "bb=" << bb << endl;   // 显示全局变量aa的值。


    cout << endl << "========================thread_synchronization_mutex========================" << endl;
}