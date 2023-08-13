//
//  funcs.cpp
//  005fundamentalsOfFunc
//
//  Created by Lee ChenZe on 8/13/23.
//

#include "funcs.hpp"

// 函数定义
void func1() {
    string localMsg = "func1局部变量message";
    cout << msg << endl;
    cout << localMsg << endl;
}
void func1(string param) {
    cout << param << endl;
}

void func2() {
    int a = 10;
    static int b = 10;
    cout << "a++: " << a++ << " | " << "b++: " << b++ << endl;
}

void func3() {
    string msg = "func1局部变量message";
    cout << "msg = " << msg << endl;
    cout << "::msg = " << ::msg << endl;
}

void func4(int no, string msg) {
    cout << "亲爱的" << no << "号技师," << msg << endl;
}
