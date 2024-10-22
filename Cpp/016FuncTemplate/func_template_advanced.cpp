//
// Created by Lee ChenZe on 10/22/24.
//
#include <iostream>

using namespace std;

template<typename T1, typename T2>
auto func(T1 x, T2 y) -> decltype(x + y) {
    auto tmp = x + y;
    cout << "tmp=" << tmp << endl;
}


void func_template_advanced() {
    cout << endl << "========================func_template_advanced========================" << endl;

    short a = 3;
    char b = 5;
    func(a, b);

    cout << endl << "========================func_template_advanced========================" << endl;
}