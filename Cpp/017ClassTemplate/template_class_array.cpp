//
// Created by Lee ChenZe on 10/26/24.
//

#include <iostream>         // 包含头文件。

using namespace std;        // 指定缺省的命名空间。

template<class T, int len = 10>
class Array {
private:
    T items[len];      // 数组元素。
public:
    Array() {}           // 默认构造函数。
    ~Array() {}         // 析构函数
    T &operator[](int ii) { return items[ii]; }  // 重载操作符[]，可以修改数组中的元素。
    const T &operator[](int ii) const { return items[ii]; }  // 重载操作符[]，不能修改数组中的元素。
};

template<class T>
class Vector {
private:
    int len;               // 数组元素的个数。
    T *items;           // 数组元素。
public:
    // 默认构造函数，分配内存。
    Vector(int size = 10) : len(size) {
        items = new T[len];
    }

    ~Vector() {         // 析构函数
        delete[] items;
        items = nullptr;
    }

    void resize(int size) {         // 护展数组的内存空间。
        if (size <= len) return;   // 只能往更大扩展。
        T *tmp = new T[size];   // 分配更大的内存空间。
        for (int ii = 0; ii < len; ii++) tmp[ii] = items[ii];     // 把原来数组中的元素复制到新数组。
        delete[] items;    // 释放原来的数组。
        items = tmp;      // 让数组指针指向新数组。
        len = size;           // 扩展后的数组长度。
    }

    int size() const { return len; }     // 获取数组长度。
    T &operator[](int ii) {   // 重载操作符[]，可以修改数组中的元素。
        if (ii >= len) resize(ii + 1);    // 扩展数组。
        return items[ii];
    }

    const T &operator[](int ii) const { return items[ii]; }  // 重载操作符[]，不能修改数组中的元素。
};

void template_class_array() {
    cout << endl << "========================template_class_array========================" << endl;

    // Array<string,10> aa;  // 创建模板类Array的对象。
    Vector<int> aa(1);     // 创建模板类Vector的对象。
    aa[0] = 5;
    aa[1] = 8;
    aa[2] = 3;
    aa[3] = 2;
    aa[4] = 7;
    // aa[0] = "西施"; aa[1] = "冰冰"; aa[2] = "幂幂"; aa[3] = "金莲"; aa[4] = "小乔";

    for (int ii = 0; ii < 5; ii++) cout << "aa[" << ii << "]=" << aa[ii] << endl;


    cout << endl << "========================template_class_array========================" << endl;
}