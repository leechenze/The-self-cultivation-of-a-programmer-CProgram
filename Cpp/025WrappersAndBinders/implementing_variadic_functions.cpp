//
// Created by Lee ChenZe on 6/3/25.
//
#include <iostream>
#include <thread>
#include <functional>
using namespace std;

void show6() {  // 普通函数。
    cout << "亲爱的，我是一只傻傻鸟。\n";
}

void show7(const string& message) {  // 普通函数。
    cout << "亲爱的，" << message << endl;
}

struct CC	// 类中有普通成员函数。
{
    void show8(int bh, const string& message) {
        cout << "亲爱的" << bh << "号，" << message << endl;
    }
};

template<typename Fn, typename...Args>
auto show5(Fn&& fn, Args&&...args) -> decltype(bind(forward<Fn>(fn), forward<Args>(args)...))
{
    cout << "表白前的准备工作......\n";

    auto f = bind(forward<Fn>(fn), forward<Args>(args)...);
    f();

    cout << "表白完成。\n";
    return f;
}


void implementing_variadic_functions() {
    cout << endl << "========================implementing_variadic_functions========================" << endl;

    show5(show6);
    show5(show7,"我是一只傻傻鸟。");
    CC cc;
    auto f = show5(&CC::show8,&cc, 3,"我是一只傻傻鸟。");
    f();

    //thread t1(show6);
    //thread t2(show7,"我是一只傻傻鸟。");
    //CC cc;
    //thread t3(&CC::show8,&cc, 3,"我是一只傻傻鸟。");
    //t1.join();
    //t2.join();
    //t3.join();

    cout << endl << "========================implementing_variadic_functions========================" << endl;
}
