//
// Created by Lee ChenZe on 10/5/24.
//

#include "iostream"

using namespace std;

// 基类
class A {
public:
    int m_a = 10;
protected:
    int m_b = 20;
private:
    int m_c = 30;
};

// 派生类
class B : public A {
public:
    using A::m_b;         // 把m_b的权限修改为公有的。
private:
    using A::m_a;         // 把m_a的权限修改为私有的。
};

void inherit_mode() {
    cout << endl;

    B b;
    // b.m_a = 11;
    b.m_b = 21;
    //b.m_c = 21;

    cout << "==========================inherit_mode==========================" << endl;
}