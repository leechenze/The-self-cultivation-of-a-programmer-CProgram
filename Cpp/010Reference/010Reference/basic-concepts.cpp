//
//  basic-concepts.cpp
//  010Reference
//
//  Created by Lee ChenZe on 8/30/23.
//

#include <iostream>
using namespace std;
// 传值
void func1(int no, string str);
// 传地址
void func2(int* no, string* str);
// 传引用
void func3(int& no, string& str);
// 二级指针做为参数传递(动态分配内存)
void func4(int** p);
// 使用引用做为参数传递(动态分配内存)
void func5(int*& p);


void basic_concepts() {
    cout << endl;
    
    // 基本语法
    int a = 3;
    int& ra = a;
    
    cout << "a的地址是: " << &a << ", a的值是: " << a << endl;
    cout << "ra的地址是: " << &ra << ", ra的值是: " << ra << endl;
    
    ra = 8;
    
    cout << "a的地址是: " << &a << ", a的值是: " << a << endl;
    cout << "ra的地址是: " << &ra << ", ra的值是: " << ra << endl;
    
    // 引用的本质
    // 声明一个指针常量
    int* const rb = &a;
    cout << "rb的地址是: " << &rb << ", rb的值是: " << rb << ", *rb解引用是: " << *rb << endl;
    
    cout << endl;
    //引用用于函数的参数
    int bh = 3;
    string msg = "我是一只金凤凰";
    // func1(bh, msg);
    // func2(&bh, &msg);
    func3(bh, msg);
    cout << "亲爱的" << bh << "号, " << msg << endl;
    
    // 二级指针的传递改用引用传递
    cout << endl;
    int* p = nullptr;
    // func4(&p);
    func5(p);
    cout << "main 中内存地址是: " << p << ", 内存中的值是: " << *p << endl;
    
    
    
    
    
    cout << endl << endl << "==================basic-concepts==================" << endl;
}
void func1(int no, string str){
    no = 8;
    str = "我是一只小小鸟";
    cout << "亲爱的" << no << "号, " << str << endl;
}
void func2(int* no, string* str) {
    *no = 8;
    *str = "我是一只小小鸟";
    cout << "亲爱的" << *no << "号, " << *str << endl;
}
void func3(int& no, string& str){
    no = 8;
    str = "我是一只小小鸟";
    cout << "亲爱的" << no << "号, " << str << endl;
}
void func4(int** p){
    *p = new int(8);
    cout << "func4的内存地址是: " << *p << ", 内存中的值是: " << **p << endl;
}
void func5(int*& p){
    p = new int(8);
    cout << "func5的内存地址是: " << p << ", 内存中的值是: " << *p << endl;
}
