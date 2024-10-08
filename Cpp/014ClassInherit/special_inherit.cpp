//
// Created by Lee ChenZe on 10/5/24.
//

#include "iostream"

using namespace std;


class A3 {        // 基类
public:
    int m_a = 0;
private:
    int m_b = 0;
public:
    // 显示基类A3全部的成员。
    void show() { cout << "A3::show() m_a=" << m_a << ",m_b=" << m_b << endl; }

    // 设置成员m_b的值。
    void setb(int b) { m_b = b; }
};

class B3 : public A3        // 派生类
{
public:
    int m_c = 0;

    // 显示派生类B3全部的成员。
    void show() { cout << "B3::show() m_a=" << m_a << ",m_c=" << m_c << endl; }
};


void special_inherit() {
    cout << endl;

    B3 b;
    A3 *a = &b;

    b.m_a = 10;
    b.setb(20);          // 设置成员m_b的值。
    b.m_c = 30;
    b.show();            // 调用的是B3类的show()函数。

    a->m_a = 11;
    a->setb(22);          // 设置成员m_b的值。
    // a->m_c = 30;

    a->show();         // 调用的是A3类的show()函数。

    cout << "==========================special_inherit==========================" << endl;
}