//
// Created by Lee ChenZe on 1/27/24.
//

#include <iostream>

using namespace std;


class CGirl2 {
public:
    int num;
    string name;
    // 计划使用堆区内存
    int *ptr;

    CGirl2() {
        ptr = nullptr;
    }

    ~CGirl2() {
        // 析构函数中释放指针指向的内存空间
        if (ptr) {
            delete ptr;
            ptr = nullptr;
        }
    }

    void show() {
        cout << "number : " << num << ", name is : " << name << ", ptr : " << ptr << endl;
    }

    CGirl2 &operator=(const CGirl2 &g) {
        // 由于可能会出现 g1 = g1 的情况，也就是自己给自己赋值的情况，所以这里做一下判断，
        if (this == &g) {
            return *this;
        }

        if (g.ptr == nullptr) {
            // 如果源对象的指针为空，则清空目标对象的内存和指针
            if (ptr != nullptr) {
                delete ptr;
                ptr = nullptr;
            }
        } else {
            // 如果目标对象的指针为空，先分配内存
            if (ptr == nullptr) {
                ptr = new int;
            }
            // 然后，把源对象内存中的数据赋值到目标对象的内存中
            memcpy(ptr, g.ptr, sizeof(int));
        }


        num = g.num;
        name = g.name;
        cout << "Called overloaded assignment function" << endl;
        return *this;
    }
};


void overloading_assignment_operators() {

    cout << endl;

    CGirl2 g1, g2;
    g1.num = 1;
    g1.name = "Roosevelt";
    g1.ptr = new int(3);
    g1.show();
    g2.show();

    g2 = g1;
    g2.show();

    cout << "*g1.ptr : " << *g1.ptr << ", *g2.ptr : " << *g2.ptr << endl;


    cout << endl << endl << "==================overloading_assignment_operators==================" << endl;
}