//
// Created by Lee ChenZe on 10/8/24.
//

#include "iostream"

using namespace std;

class A4 {
public:
    int m_a = 10;
};

class B4 : virtual public A4 {
};

class C4 : virtual public A4 {
};

class D4 : public B4, public C4 {
};


void more_and_virtual_inherit() {
    cout << endl;

    D4 d;
    // d.B::m_a = 30;
    // d.C::m_a = 80;
    d.m_a = 80;
    cout << "B::m_a的地址是：" << &d.B4::m_a << "，值是：" << d.B4::m_a << endl;
    cout << "C::m_a的地址是：" << &d.C4::m_a << "，值是：" << d.C4::m_a << endl;

    cout << "==========================more_and_virtual_inherit==========================" << endl;
}