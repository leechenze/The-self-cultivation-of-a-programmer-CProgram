//
// Created by Lee ChenZe on 10/8/24.
//

#include <iostream>

using namespace std;

class AA {                    // 基类
public:
    AA() { cout << "调用了基类的构造函数AA()。\n"; }

    virtual void func() { cout << "调用了基类的func()。\n"; }

    virtual ~AA() { cout << "调用了基类的析构函数~AA()。\n"; }
    // virtual ~AA() {}
};

class BB : public AA {  // 派生类
public:
    BB() { cout << "调用了派生类的构造函数BB()。\n"; }

    void func() { cout << "调用了派生类的func()。\n"; }

    ~BB() { cout << "调用了派生类的析构函数~BB()。\n"; }
};

void destruct_derived_classes() {
    cout << endl;

    // BB b;

    AA *a = new BB;
    delete a;

    cout << "========================destruct_derived_classes========================" << endl;
}