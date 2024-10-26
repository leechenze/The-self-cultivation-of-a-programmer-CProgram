//
// Created by Lee ChenZe on 10/26/24.
//

#include <iostream>

using namespace std;

template<class T5, class T6>
class AA5              // 类模板AA5。
{
public:
    T5 m_x;
    T6 m_y;

    AA5(const T5 x, const T6 y) : m_x(x), m_y(y) {}

    void show() { cout << "m_x=" << m_x << "，m_y=" << m_y << endl; }

    template<class T>
    class BB {
    public:
        T m_a;
        T5 m_b;

        BB() {}

        void show();
    };

    BB<string> m_bb;

    template<typename T>
    void show(T tt);
};

template<class T5, class T6>
template<class T>
void AA5<T5, T6>::BB<T>::show() {
    cout << "m_a=" << m_a << "，m_b=" << m_b << endl;
}

template<class T5, class T6>
template<typename T>
void AA5<T5, T6>::show(T tt) {
    cout << "tt=" << tt << endl;
    cout << "m_x=" << m_x << "，m_y=" << m_y << endl;
    m_bb.show();
}


void member_template_class() {
    cout << endl << "========================member_template_class========================" << endl;

    AA5<int, string> a(88, "我是一只傻傻鸟。");
    a.show();
    a.m_bb.m_a = "我有一只小小鸟。";
    a.m_bb.show();
    a.show("你是一只什么鸟？");


    cout << endl << "========================member_template_class========================" << endl;
}
