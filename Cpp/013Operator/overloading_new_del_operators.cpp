//
// Created by Lee ChenZe on 1/27/24.
//

#include <iostream>

using namespace std;

// 参数必须是size_t（unsigned long long），返回值必须是void*。
void *operator new(size_t size) {
    cout << "调用了全局重载的new：" << size << "字节。\n";
    // 申请内存。
    void *ptr = malloc(size);
    cout << "申请到的内存的地址是：" << ptr << endl;
    return ptr;
}

// 参数必须是void *，返回值必须是void。
void operator delete(void *ptr) {
    cout << "调用了全局重载的delete。\n";
    // 对空指针delete是安全的。
    if (ptr == 0) return;
    // 释放内存。
    free(ptr);
}

// 超女类CGirl3。
class CGirl3 {
public:
    // 编号。
    int m_bh;
    // 胸围。
    int m_xw;

    CGirl3(int bh, int xw) {
        m_bh = bh, m_xw = xw;
        cout << "调用了构造函数CGirl3()\n";
    }

    ~CGirl3() { cout << "调用了析构函数~CGirl3()\n"; }

    // 参数必须是size_t（unsigned long long），返回值必须是void*。
    void *operator new(size_t size) {
        cout << "调用了类的重载的new：" << size << "字节。\n";
        // 申请内存。
        void *ptr = malloc(size);
        cout << "申请到的内存的地址是：" << ptr << endl;
        return ptr;
    }

    // 参数必须是void *，返回值必须是void。
    void operator delete(void *ptr) {
        cout << "调用了类的重载的delete。\n";
        // 对空指针delete是安全的。
        if (ptr == 0) return;
        // 释放内存。
        free(ptr);
    }
};

void overloading_new_del_operators() {

    cout << endl;

    // int *p1 = new int(3);
    // cout << "p1= " << (void *) p1 << ", *p1= " << *p1 << endl;
    // delete p1;

    CGirl3 *p2 = new CGirl3(3, 8);
    cout << "p2的地址是：" << p2 << "编号：" << p2->m_bh << "，胸围：" << p2->m_xw << endl;
    delete p2;


    cout << endl << endl << "==================overloading_new_del_operators==================" << endl;
}