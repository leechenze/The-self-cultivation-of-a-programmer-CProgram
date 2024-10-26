//
// Created by Lee ChenZe on 10/22/24.
//

#include <iostream>

using namespace std;


template<class T1, class T2=double>
class AA {
public:
    T1 m_a;
    T2 m_b;

    AA() {}

    // 通用类型用于成员函数的参数
    AA(T1 a, T2 b) : m_a(a), m_b(b) {}

    // 通用类型用于成员函数的返回值
    T1 geta() {
        T1 a = 2;
        return m_a + a;
    }

    T2 getb();
};

// T2 getb()函数体在类外部写，类内部只声明sgetb;
template<class T1, class T2>
T2 AA<T1, T2>::getb() {
    T1 b = 1;
    return m_b + b;
}

void class_template_basic() {
    cout << endl << "========================class_template_basic========================" << endl;

    AA<int, double> aa;
    AA<int> bb;
    aa.m_a = 20;
    aa.m_b = 10;

    cout << "aa.geta() = " << aa.geta() << endl;
    cout << "aa.getb() = " << aa.getb() << endl;


    cout << endl << "========================class_template_basic========================" << endl;
}