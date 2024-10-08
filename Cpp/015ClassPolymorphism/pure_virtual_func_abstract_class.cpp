//
// Created by Lee ChenZe on 10/8/24.
//

#include "iostream"

using namespace std;

class AA1 {                    // 基类
public:
    AA1() { cout << "调用了基类的构造函数AA1()。\n"; }

    virtual void func() = 0; // { cout << "调用了基类的func()。\n"; }

    virtual ~AA1() { cout << "调用了基类的析构函数~AA1()。\n"; }
};

class BB1 : public AA1 {  // 派生类
public:
    BB1() { cout << "调用了派生类的构造函数BB1()。\n"; }

    void func() { cout << "调用了派生类的func()。\n"; }

    ~BB1() { cout << "调用了派生类的析构函数~BB1()。\n"; }
};

void pure_virtual_func_abstract_class() {
    cout << endl;

    BB1 b;
    // 用指针（和用引用的效果相同）
    AA1 *r = &b;
    r->func();
    // 用引用（和用指针的效果相同）
    // AA1 &r = b;
    // r.func();

    cout << "========================pure_virtual_func_abstract_class========================" << endl;
}