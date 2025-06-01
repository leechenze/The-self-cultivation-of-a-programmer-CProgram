//
// Created by Lee ChenZe on 6/1/25.
//
#include <iostream>
#include <string>

using namespace std;


void print(string& s) {
    cout << "左值引用函数: " << s << endl;
}

void print(string&& s) {
    cout << "右值引用函数: " << s << endl;
}

// 非完美转发：参数类型写成 string&&，左值无法调用
void wrong_forward(string&& s) {
    // ❌ 这里 s 是一个左值，调用的是左值版本的 print
    print(s);
}

// 完美转发
template<typename T>
void perfect_forward(T&& arg) {
    // ✅ 根据原本的 T 推导出左值/右值
    print(forward<T>(arg));
}


void perfect_forwarding() {
    cout << endl << "========================perfect_forwarding========================" << endl;

    string msg = "hello";

    cout << "--- 非完美转发 ---" << endl;
    // wrong_forward(msg); // ❌ 编译失败，不能将左值传给 string&&
    wrong_forward(move(msg)); // ✅ 被视作右值

    cout << "--- 完美转发 ---" << endl;
    perfect_forward(msg);           // 推导为 string& -> 左值版本
    perfect_forward(move(msg)); // 推导为 string&& -> 右值版本

    cout << endl << "========================perfect_forwarding========================" << endl;
}
