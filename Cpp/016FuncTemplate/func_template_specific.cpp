//
// Created by Lee ChenZe on 10/22/24.
//
#include <iostream>

using namespace std;


class CGirl1            // 超女类。
{
public:
    int m_bh;              // 编号。
    string m_name;   // 姓名。
    int m_rank;          // 排名。
};

template<typename T>
void Swap(T &a, T &b) {      // 交换两个变量的值函数模板。
    T tmp = a;
    a = b;
    b = tmp;
    cout << "调用了Swap(T& a, T& b)\n";
}

template<>
void Swap(CGirl1 &g1, CGirl1 &g2) {      // 交换两个超女对象的排名。
// void Swap<CGirl1>(CGirl1 &g1, CGirl1 &g2) {
    int tmp = g1.m_rank;
    g1.m_rank = g2.m_rank;
    g2.m_rank = tmp;
    cout << "调用了Swap(CGirl& g1, CGirl& g2)\n";
}


void func_template_specific() {
    cout << endl << "========================func_template_specific========================" << endl;

    int a = 10, b = 20;
    Swap(a, b);           // 使用了函数模板。
    cout << "a=" << a << ",b=" << b << endl;

    CGirl1 g1, g2;
    g1.m_rank = 1;
    g2.m_rank = 2;
    Swap(g1, g2);     // 使用了超女类的具体化函数。
    cout << "g1.m_rank=" << g1.m_rank << ",g2.m_rank=" << g2.m_rank << endl;

    cout << endl << "========================func_template_specific========================" << endl;
}