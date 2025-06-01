//
// Created by Lee ChenZe on 6/1/25.
//
#include <iostream>
#include <string>

using namespace std;

void print() {
    cout << "(参数打印完毕)" << endl;
}

template<typename T, typename... Args>
void print(T first, Args... rest) {
    cout << "参数: " << first << endl;
    // 递归调用自己展开参数
    print(rest...);
}


void variadic_templates() {
    cout << endl << "========================variadic_templates========================" << endl;

    print(42, 3.14, "Hello", 'A');

    cout << endl << "========================variadic_templates========================" << endl;
}
