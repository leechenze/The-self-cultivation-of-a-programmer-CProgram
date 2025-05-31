//
// Created by Lee ChenZe on 5/31/25.
//
#include <iostream>;
#include <string>;

using namespace std;

class A{
private:
    int m_a;
    int m_b;
    double m_c;
public:
    // 有一个参数的构在函数，初始化m_c成员
    A(double c){
        m_c = c + 3;
        cout << "A(double c) = " << endl;
    }
    // 有两个参数的构造函数，初始化m_a和m_b
    A(int a, int b) {
        m_a = a + 1;
        m_b = b + 1;
        cout << " AA(int a, int b) = " << endl;
    }

    // 构造函数委托A(int a, int b)初始化m_a和m_b
    A(int a, int b, const string& str) : A(a, b) {
        A(a,b);
        cout << "m_a=" << m_a << ",m_b=" << m_b << ",str=" << str << endl;
    }
    // 构造函数委托A(double c)初始化m_c
    A(double c, const string& str) : A(c) {
        cout << "m_c=" << m_c << ",str=" << str << endl;
    }

};

void delegate_construction_and_inheritance_construction() {
    cout << endl << "========================delegate_construction_and_inheritance_construction========================" << endl;



    cout << endl << "========================delegate_construction_and_inheritance_construction========================" << endl;
}
