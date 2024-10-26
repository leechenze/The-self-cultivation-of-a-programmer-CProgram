//
// Created by Lee ChenZe on 10/26/24.
//

#include <iostream>

using namespace std;


template<class T3, class T4>
class AA4    // 模板类AA4。
{
public:
    T3 m_x;
    T4 m_y;

    AA4(const T3 x, const T4 y) : m_x(x), m_y(y) {}

    void show() const { cout << "show()  x = " << m_x << ", y = " << m_y << endl; }
};

// 采用普通函数，参数和返回值是模板类AA4的实例化版本。
AA4<int, string> func(AA4<int, string> &aa) {
    aa.show();
    cout << "调用了func(AA4<int, string> &aa)函数。\n";
    return aa;
}

// 函数模板，参数和返回值是的模板类AA4。
template<typename T3, typename T4>
AA4<T3, T4> func(AA4<T3, T4> &aa) {
    aa.show();
    cout << "调用了func(AA4<T3, T4> &aa)函数。\n";
    return aa;
}

// 函数模板，参数和返回值是任意类型。
template<typename T>
T func(T &aa) {
    aa.show();
    cout << "调用了func(AA4<T> &aa)函数。\n";
    return aa;
}

void template_class_func() {
    cout << endl << "========================template_class_func========================" << endl;

    AA4<int, string> aa(3, "我是一只傻傻鸟。");
    func(aa);

    cout << endl << "========================template_class_func========================" << endl;
}
