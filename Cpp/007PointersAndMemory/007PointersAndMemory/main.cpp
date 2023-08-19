//
//  main.cpp
//  007PointersAndMemory
//
//  Created by Lee ChenZe on 8/19/23.
//

#include <iostream>
using namespace std;

void func1(int* no, string* msg);
void func2(int a, int b, int c, int* max, int* min);

int main(int argc, const char * argv[]) {
    
    cout << endl;
    /** =========指针的基本概念========= */
    int a;
    char b;
    bool c;
    string d;
    
    cout << "变量a的地址是:" << &a << endl;
    cout << "变量b的地址是:" << &b << endl;
    cout << "变量c的地址是:" << &c << endl;
    cout << "变量d的地址是:" << &d << endl;
    
    cout << endl;
    cout << "变量a的地址是:" << (void*)&a << endl;
    cout << "变量b的地址是:" << (void*)&b << endl;
    cout << "变量c的地址是:" << (void*)&c << endl;
    cout << "变量d的地址是:" << (void*)&d << endl;
    
    cout << endl;
    cout << "变量a的地址是:" << (long long)&a << endl;
    cout << "变量b的地址是:" << (long long)&b << endl;
    cout << "变量c的地址是:" << (long long)&c << endl;
    cout << "变量d的地址是:" << (long long)&d << endl;
    
    int *pa = &a;
    char *pb = &b;
    bool *pc = &c;
    string *pd = &d;
    cout << endl;
    // 指针默认是用十六进制表示的,不过为了方便我们都用 long long 转为十进制.
    cout << "指针pa的值是:" << (long long)pa << endl;
    cout << "指针pb的值是:" << (long long)pb << endl;
    cout << "指针pc的值是:" << (long long)pc << endl;
    cout << "指针pd的值是:" << (long long)pd << endl;
    
    
    cout << endl;
    /** =========使用指针========= */
    int a1 = 3;
    int* p1 = &a1;
    int* p2 = &a1;
    cout << "a1 = " << a1 << endl;
    cout << "*p1 = " << *p1 << endl;
    // 如下等同于 a1 = 8, 推理一下, 过程如下:
    // p1 == &a1
    // *p1 == *&a1 == a1
    *p1 = 8;
    cout << "a1 = " << a1 << endl;
    cout << "*p1 = " << *p1 << endl;
    cout << "*p2 = " << *p2 << endl;
    
    
    cout << endl;
    /** =========指针用于函数的参数========= */
    int a2 = 3;
    string messages = "我是一只小小鸟";
    
    // func1代码中参数为引用内存地址
    func1(&a2, &messages);
    cout << "亲爱的" << a2 << "号超女:" << messages << endl;
    // 模拟代码,即func1函数中的那些代码.
    {
        // int* no = &a2;
        // string* msg = &messages;
        // cout << "亲爱的" << *no << "号超女:" << *msg << endl;
        // *no = 8;
        // *msg = "我是刘德华";
        // cout << "亲爱的" << a2 << "号超女:" << messages << endl;
    }
    // 实际开发中对修改函数中实参值的应用场景非常多,如下例子:
    // 这个例子用于求a3, b3, c3中的最大值和最小值.
    int a3 = 180, b3 = 170, c3 = 175, largest,smallest;
    func2(a3, b3, c3, &largest, &smallest);
    cout << "largest = " << largest << ", smallest = " << smallest << endl;
    
    
    cout << endl;
    /** =========用const修饰指针========= */
    // TODO
    
    
    
    
    
    
    
    cout << endl;
}

void func1(int* no, string* msg) {
    cout << "func1:亲爱的" << *no << "号超女:" << *msg << endl;
     *no = 8;
     *msg = "我是蔡徐坤";
}
void func2(int a, int b, int c, int* max, int* min){
    *max = a > b ? a : b;           // 取a和b中的大者
    *min = a < b ? a : b;           // 取a和b中的小者
    *max = *max > c ? *max : c;     // 取max和c中的大者
    *min = *min < c ? *min : c;     // 取min和c中的小者
}

