//
// Created by Lee ChenZe on 10/8/24.
//

#include <stdio.h>
#include <iostream>

using namespace std;


class CAllComers {        // 报名者类
public:
    int m_bh = 0;             // 编号。
    virtual void show() { cout << "CAllComers::show()：我是" << m_bh << "号。 " << endl; }

    virtual void show(int a) { cout << "CAllComers::show(int a)：我是" << m_bh << "号。 " << endl; }
};

class CGirl : public CAllComers {        // 超女类
public:
    int m_age = 0;           // 年龄。
    void show() { cout << "CGirl::show()：我是" << m_bh << "号， " << m_age << "岁。" << endl; }

    void show(int a) { cout << "CGirl::show(int a)：我是" << m_bh << "号， " << m_age << "岁。" << endl; }
};

void polymorphism_base_concept() {
    cout << endl;

    CAllComers a;
    a.m_bh = 3;                             // 创建基类对象并对成员赋值。
    CGirl g;
    g.m_bh = 8;
    g.m_age = 23;    // 创建派生类对象并对成员赋值。

    CAllComers *p;            // 声明基类指针。
    //p = &a;   p->show();   // 让基类指针指向基类对象，并调用虚函数。
    p = &g;
    p->show();   // 让基类指针指向派生类对象，并调用虚函数。
    p->show(5);
    p->CAllComers::show(5);

    cout << "========================polymorphism_base_concept========================" << endl;
}