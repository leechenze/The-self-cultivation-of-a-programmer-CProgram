//
// Created by Lee ChenZe on 10/5/24.
//

#include "iostream"

using namespace std;

class A1 {        // 基类
public:
    int m_a;
private:
    int m_b;
public:
    A1() : m_a(0), m_b(0)                     // 基类的默认构造函数。
    {
        cout << "调用了基类的默认构造函数A1()。\n";
    }

    A1(int a, int b) : m_a(a), m_b(b)     // 基类有两个参数的构造函数。
    {
        cout << "调用了基类的构造函数A1(int a,int b)。\n";
    }

    A1(const A1 &a) : m_a(a.m_a + 1), m_b(a.m_b + 1)   // 基类的拷贝构造函数。
    {
        cout << "调用了基类的拷贝构造函数A1(const A1 &a)。\n";
    }

    // 显示基类A1全部的成员。
    void showA1() { cout << "m_a=" << m_a << ",m_b=" << m_b << endl; }
};

class B1 : public A1        // 派生类
{
public:
    int m_c;

    B1() : m_c(0), A1()             // 派生类的默认构造函数，指明用基类的默认构造函数（不指明也无所谓）。
    {
        cout << "调用了派生类的默认构造函数B1()。\n";
    }

    B1(int a, int b, int c) : A1(a, b), m_c(c)           // 指明用基类的有两个参数的构造函数。
    {
        cout << "调用了派生类的构造函数B1(int a,int b,int c)。\n";
    }

    B1(const A1 &a, int c) : A1(a), m_c(c)              // 指明用基类的拷贝构造函数。
    {
        cout << "调用了派生类的构造函数B1(const A1 &a,int c) 。\n";
    }

    // 显示派生类B1全部的成员。
    void showB1() { cout << "m_c=" << m_c << endl << endl; }
};


void structure_basic_class() {
    cout << endl;

    B1 b1;                 // 将调用基类默认的构造函数。
    b1.showA1();
    b1.showB1();

    B1 b2(1, 2, 3);      // 将调用基类有两个参数的构造函数。
    b2.showA1();
    b2.showB1();

    A1 a(10, 20);      // 创建基类对象。
    B1 b3(a, 30);      // 将调用基类的拷贝造函数。
    b3.showA1();
    b3.showB1();

    cout << "==========================structure_basic_class==========================" << endl;
}