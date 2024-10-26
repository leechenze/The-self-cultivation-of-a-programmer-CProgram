//
// Created by Lee ChenZe on 10/26/24.
//

#include <iostream>         // 包含头文件。

using namespace std;        // 指定缺省的命名空间。

// 类模板
template<class T11, class T22>
class AA2 {                 // 类模板。
public:
    T11 m_x;
    T22 m_y;

    AA2(const T11 x, const T22 y) : m_x(x), m_y(y) { cout << "类模板：构造函数。\n"; }

    void show() const;
};

template<class T11, class T22>
void AA2<T11, T22>::show() const {    // 成员函数类外实现。
    cout << "类模板：x = " << m_x << ", y = " << m_y << endl;
}
/////////////////////////////////////////////////////////////////////////////////////////

// 类模板完全具体化
template<>
class AA2<int, string> {
public:
    int m_x;
    string m_y;

    AA2(const int x, const string y) : m_x(x), m_y(y) { cout << "完全具体化：构造函数。\n"; }

    void show() const;
};

void AA2<int, string>::show() const {    // 成员函数类外实现。
    cout << "完全具体化：x = " << m_x << ", y = " << m_y << endl;
}
/////////////////////////////////////////////////////////////////////////////////////////

// 类模板部分具体化
template<class T11>
class AA2<T11, string> {
public:
    T11 m_x;
    string m_y;

    AA2(const T11 x, const string y) : m_x(x), m_y(y) { cout << "部分具体化：构造函数。\n"; }

    void show() const;
};

template<class T11>
void AA2<T11, string>::show() const {    // 成员函数类外实现。
    cout << "部分具体化：x = " << m_x << ", y = " << m_y << endl;
}
/////////////////////////////////////////////////////////////////////////////////////////

void template_class_specific() {
    cout << endl << "========================template_class_specific========================" << endl;

    // 具体化程度高的类优先于具体化程度低的类，具体化的类优先于没有具体化的类。
    AA2<int, string> aa1(8, "我是一只傻傻鸟。");   // 将使用完全具体化的类。
    AA2<char, string> aa2(8, "我是一只傻傻鸟。");   // 将使用部分具体化的类。
    AA2<int, double> aa3(8, 999999);                      // 将使用模板类。


    cout << endl << "========================template_class_specific========================" << endl;
}