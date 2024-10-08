//
// Created by Lee C2henZe on 10/5/24.
//

#include "iostream"

using namespace std;

class A2 {        // 基类
public:
    int m_a = 10;

    void func() { cout << "调用了A2的func()函数。\n"; }
};

class B2 : public A2 {       // 子类
public:
    int m_a = 20;

    void func() { cout << "调用了B2的func()函数。\n"; }
};

class C2 : public B2 {       // 孙类
public:
    int m_a = 30;

    void func() { cout << "调用了C2的func()函数。\n"; }

    void show() {
        cout << "C2::m_a的值是：" << C2::m_a << endl;
        cout << "B2::m_a的值是：" << B2::m_a << endl;
        cout << "A2::m_a的值是：" << B2::A2::m_a << endl;
    }
};

void name_shield_class_scope() {
    cout << endl;

    C2 c;
    cout << "C2::m_a的值是：" << c.C2::m_a << endl;
    cout << "B2::m_a的值是：" << c.B2::m_a << endl;
    cout << "A2::m_a的值是：" << c.B2::A2::m_a << endl;
    c.C2::func();
    c.B2::func();
    c.B2::A2::func();

    cout << "==========================name_shield_class_scope==========================" << endl;
}