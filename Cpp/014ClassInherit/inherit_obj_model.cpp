//
// Created by Lee ChenZe on 10/5/24.
//

#include "iostream"

using namespace std;

void *operator new(size_t size)   // 重载new运算符。
{
    void *ptr = malloc(size);        // 申请内存。
    cout << "申请到的内存的地址是：" << ptr << "，大小是：" << size << endl;
    return ptr;
}

void operator delete(void *ptr)   // 重载delete运算符。
{
    if (ptr == 0) return;       // 对空指针delete是安全的。
    free(ptr);      // 释放内存。
    cout << "释放了内存。\n";
}

class A {        // 基类
public:
    int m_a = 10;
protected:
    int m_b = 20;
private:
    int m_c = 30;
public:
    A() {
        cout << "A中this指针是： " << this << endl;
        cout << "A中m_a的地址是：" << &m_a << endl;
        cout << "A中m_b的地址是：" << &m_b << endl;
        cout << "A中m_c的地址是：" << &m_c << endl;
    }

    void func() { cout << "m_a=" << m_a << ",m_b=" << m_b << ",m_c=" << m_c << endl; }
};

class B : public A        // 派生类
{
public:
    int m_d = 40;

    B() {
        cout << "B中this指针是： " << this << endl;
        cout << "B中m_a的地址是：" << &m_a << endl;
        cout << "B中m_b的地址是：" << &m_b << endl;
        cout << "B中m_d的地址是：" << &m_d << endl;
    }

    void func1() { cout << "m_d=" << m_d << endl; }
};

void inherit_obj_model() {
    cout << endl;

    cout << "基类占用内存的大小是：" << sizeof(A) << endl;
    cout << "派生类占用内存的大小是：" << sizeof(B) << endl;

    B *b = new B;
    b->func();
    b->func1();
    // memset(b, 0, sizeof(B));

    *((int *) b + 2) = 31;        // 把基类私有成员m_c的值修改成31。
    // 代码解读：
    // (int *) b        强制转换为整型指针
    // (int *) + 2      转换后的地址加2，表示偏移两个整型的存储单元，因为m_c是第三个成员变量
    // *((int *) + 2)   再对偏移后的地址解引用，就是m_c的值。

    b->func();
    b->func1();
    delete b;


    cout << "==========================inherit_obj_model==========================" << endl;
}