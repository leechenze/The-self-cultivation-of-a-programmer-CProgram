//
//  function-return-reference.cpp
//  010Reference
//
//  Created by Lee ChenZe on 9/3/23.
//

#include <iostream>
using namespace std;


int& func1(int& pa);
void func2(const string& msg = "我是一只小小鸟");
void func3(int bh, const string &name = "西施", const string &msg = "我是一只小小鸟");
void func4(int& a, int& b);
void func4(string& a, string& b);
inline void func5(const int no, const string msg){
    cout << no << msg << endl;
}

void function_return_reference() {
    cout << endl;
    int a = 8;
    int& b = func1(a);
    cout << "a的地址是 = " << &a << "a = " << a << endl;
    cout << "b的地址是 = " << &b << "b = " << b << endl;
    
    // 函数默认参数
    cout << endl;
    func2();
    func2("我是一只金凤凰");
    
    // 函数重载
    int a1 = 5;
    int b1 = 8;
    func4(a1, b1);
    cout << "a1 = " << a1 << ", b1 = " << b1 << endl;
    string a2 = "harris";
    string b2 = "hillary";
    func4(a2, b2);
    cout << "a2 = " << a2 << ", b2 = " << b2 << endl;
    
    // 内联函数
    func5(10, "我是一只金凤凰");
    
    
    
    
    
    cout << endl << endl << "==================function-return-reference==================" << endl;
}

int &func1(int& pa) {
    pa++;
    cout << "pa的地址是 = " << &pa << "pa = " << pa << endl;
    return pa;
};
void func2(const string &msg){
    cout << msg << endl;
};
void func4(int& a, int& b){
    int tmp = a;
    a = b;
    b = tmp;
}
void func4(string& a, string& b){
    string tmp = a;
    a = b;
    b = tmp;
}
