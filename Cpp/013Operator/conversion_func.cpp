//
// Created by Lee ChenZe on 10/5/24.
//
#include "iostream"

using namespace std;

class CGirl8       // 超女类CGirl8。
{
public:
    int m_bh;           // 编号。
    string m_name;     // 姓名。
    double m_weight;   // 体重，单位：kg。

    // 默认构造函数。
    CGirl8() {
        m_bh = 8;
        m_name = "douglas";
        m_weight = 50.7;
    }

    explicit operator int() { return m_bh; }

    int to_int() { return m_bh; }

    operator string() { return m_name; }

    explicit operator double() { return m_weight; }
};


void conversion_func() {
    cout << endl;

    string name = "douglas";                // char * 转换成 string
    // const char *ptr = name;                 // string 转换成 char *，错误
    const char *ptr = name.c_str();         // 返回char *，正确

    CGirl8 g;
    int a = g.to_int();
    cout << "a的值是：" << a << endl;
    string b = string(g);
    cout << "b的值是：" << b << endl;
    double c = double(g);
    cout << "c的值是：" << c << endl;
    short d = (int) g;

    cout << endl << endl << "==================conversion_func==================" << endl;
}