//
// Created by Lee ChenZe on 10/4/24.
//

// 包含头文件。
#include <iostream>

// 指定缺省的命名空间。
using namespace std;

// 超女类CGirl6。
class CGirl6 {
public:
    string m_name;
    int m_ranking;

    CGirl6() {
        m_name = "douglas";
        m_ranking = 5;
    }

    void reveal() const {
        cout << "姓名: " << m_name << ",排名: " << m_ranking << endl;
    }

    // ++前置的重载函数
    CGirl6 &operator++() {
        m_ranking++;
        return *this;
    }

    // ++后置的重载函数
    CGirl6 operator++(int) {
        CGirl6 temp = *this;
        m_ranking++;
        return temp;
    }

};


void overloading_unary_operators() {
    cout << endl;

    int i60 = 0, i61 = 0;

    int i62 = ++i60;
    cout << "i62 = " << i62 << ", i60 =" << i60 << endl;
    int i63 = i61++;
    cout << "i63 = " << i63 << ", i61 =" << i61 << endl;

    CGirl6 cGirl60, cGirl61, cGirl62, cGirl63;
    ++(++(++cGirl60));
    cGirl60.reveal();
    cGirl61++;
    cGirl61.reveal();

    CGirl6 cGirl64 = ++cGirl62;
    cout << "cGirl64.m_ranking = " << cGirl64.m_ranking << ", cGirl62.m_ranking =" << cGirl62.m_ranking << endl;
    CGirl6 cGirl65 = cGirl63++;
    cout << "cGirl65.m_ranking = " << cGirl65.m_ranking << ", cGirl63.m_ranking =" << cGirl63.m_ranking << endl;


    cout << endl << endl << "==================overloading_unary_operators==================" << endl;
}