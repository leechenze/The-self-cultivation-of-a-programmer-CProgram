//
// Created by Lee ChenZe on 6/1/25.
//
#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

// 普通函数
void func(int bh, const string &str){
    for(int i = 0; i < 10; i++) {
        cout << "第" << i << "次表白：亲爱的" << bh << "号，" << str << endl;
        this_thread::sleep_for(chrono::seconds(1));
    }
}
// lambda函数
auto lfunc = [](int bh, const string &str){
    for(int i = 0; i < 10; i++) {
        cout << "第" << i << "次表白：亲爱的" << bh << "号，" << str << endl;
        this_thread::sleep_for(chrono::seconds(1));
    }
};
// 仿函数
class ob_func{
public:
    void operator() (int bh, const string &str){
        for(int i = 0; i < 10; i++) {
            cout << "第" << i << "次表白：亲爱的" << bh << "号，" << str << endl;
            this_thread::sleep_for(chrono::seconds(1));
        }
    };
};
// 类的静态成员函数
class class_static_func{
public:
    static void func(int bh, const string &str){
        for(int i = 0; i < 10; i++) {
            cout << "第" << i << "次表白：亲爱的" << bh << "号，" << str << endl;
            this_thread::sleep_for(chrono::seconds(1));
        }
    }
};
// 类的普通成员函数
class class_func{
public:
    void func(int bh, const string &str){
        for(int i = 0; i < 10; i++) {
            cout << "第" << i << "次表白：亲爱的" << bh << "号，" << str << endl;
            this_thread::sleep_for(chrono::seconds(1));
        }
    }
};


void create_thread() {
    cout << endl << "========================create_thread========================" << endl;

    // // 用普通函数创建线程
    // thread t1(func, 3, "I'm leonardo");
    // thread t2(func, 8, "I'm hamilton");
    // // 用lambda函数创建线程
    // thread t3(lfunc, 10, "I'm beckham");
    // // 用仿函数创建线程
    // thread t4(ob_func(), 10, "I'm abraham");
    // // 用类的静态成员函数创建线程
    // thread t5(class_static_func::func, 1, "I'm stephen");
    // // 用类的普通成员函数创建线程
    // // 这么做是为了要保证，cf对象的生命周期要比子线程要长，否则如果对象销毁，就会发生内存泄露
    // class_func cf;
    // thread t6(&class_func::func, &cf, 1, "I'm florida");



    // cout << "任务开始" << endl;
    // for (int i = 0; i < 10; i++) {
    //     cout << "主线程任务执行中..." << endl;
    //     // 假设执行任务需要用时
    //     this_thread::sleep_for(chrono::seconds(1));
    // }
    // cout << "任务完成" << endl;

    // 回收线程资源
    // t1.join();
    // t2.join();
    // t3.join();
    // t4.join();
    // t6.join();

    cout << endl << "========================create_thread========================" << endl;
}
