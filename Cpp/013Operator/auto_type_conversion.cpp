//
// Created by Lee ChenZe on 10/5/24.
//

#include "iostream"

using namespace std;


class CGirl7       // 超女类CGirl。
{
public:
    int m_bh;           // 编号。
    string m_name;     // 姓名。
    double m_weight;   // 体重，单位：kg。

    // 默认构造函数。
    CGirl7() {
        m_bh = 0;
        m_name.clear();
        m_weight = 0;
        cout << "调用了CGirl7()\n";
    }

    // 自我介绍的方法。
    void show() { cout << "bh=" << m_bh << ",name=" << m_name << ",weight=" << m_weight << endl; }

    // explicit关键字将禁用隐式转换，但仍可以进行显示转换。
    explicit CGirl7(int bh) {
        m_bh = bh;
        m_name.clear();
        m_weight = 0;
        cout << "调用了CGirl7(int bh)\n";
    }

    CGirl7(double weight) {
        m_bh = 0;
        m_name.clear();
        m_weight = weight;
        cout << "调用了CGirl7(double weight)\n";
    }
};

void func(CGirl7 cg) {
    cg.show();
}

CGirl7 func1() {
    return 8;
}

void auto_type_conversion() {
    cout << endl;

    // CGirl7 g1(8);                 // 常规的写法。
    // CGirl7 g1 = CGirl7(8);        // 显式转换。
    // CGirl7 g1 = 8;                // 隐式转换。
    CGirl7 g1;                      // 创建对象。
    g1 = (CGirl7) 8;             // 隐式转换，用CGirl7(8)创建临时对象，再赋值给g。
    // CGirl7 g1 = 8.7;                // 隐式转换。
    // g1.show();

    func(8);
    func1();

    cout << endl << endl << "==================auto_type_conversion==================" << endl;
}