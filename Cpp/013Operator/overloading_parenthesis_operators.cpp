//
// Created by Lee ChenZe on 1/27/24.
//

// 包含头文件。
#include <iostream>

// 指定缺省的命名空间。
using namespace std;

// 超女类CGirl5。
class CGirl5 {
public:
    void operator()(string str) {
        cout << "括号运算符重载函数: " << str << endl;
    }
};


int overloading_parenthesis_operators() {
    cout << endl;

    CGirl5 cgirl5;
    cgirl5("超女类5");

    cout << endl << endl << "==================overloading_parenthesis_operators==================" << endl;
}