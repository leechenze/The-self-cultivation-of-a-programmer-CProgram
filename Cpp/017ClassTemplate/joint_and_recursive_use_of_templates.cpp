//
// Created by Lee ChenZe on 10/26/24.
//

#include <iostream>

using namespace std;

template<class DataType1>
class Stack1       // 栈类
{
private:
    DataType1 *items;               // 栈数组。
    int stacksize;         // 栈实际的大小。
    int top;                  // 栈顶指针。
public:
    // 构造函数：1）分配栈数组内存；2）把栈顶指针初始化为0。
    Stack1(int size = 3) : stacksize(size), top(0) {
        items = new DataType1[stacksize];
    }

    ~Stack1() {
        delete[] items;
        items = nullptr;
    }

    Stack1 &operator=(const Stack1 &v)   // 重载赋值运算符函数，实现深拷贝。
    {
        delete[] items;         // 释放原内存。
        stacksize = v.stacksize;     // 栈实际的大小。
        items = new DataType1[stacksize];   // 重新分配数组。
        for (int ii = 0; ii < stacksize; ii++) items[ii] = v.items[ii];    // 复制数组中的元素。
        top = v.top;     // 栈顶指针。
        return *this;
    }

    bool isempty() const {            // 判断栈是否为空。
        return top == 0;
    }

    bool isfull() const {                 // 判断栈是否已满。
        return top == stacksize;
    }

    bool push(const DataType1 &item) {   // 元素入栈。
        if (top < stacksize) {
            items[top++] = item;
            return true;
        }
        return false;
    }

    bool pop(DataType1 &item) {               // 元素出栈。
        if (top > 0) {
            item = items[--top];
            return true;
        }
        return false;
    }
};

template<class T1>
class Vector1           // 动态数组。
{
private:
    int len;               // 数组元素的个数。
    T1 *items;           // 数组元素。
public:
    // 默认构造函数，分配内存。
    Vector1(int size = 2) : len(size) {
        items = new T1[len];
    }

    ~Vector1() {         // 析构函数
        delete[] items;
        items = nullptr;
    }

    Vector1 &operator=(const Vector1 &v)   // 重载赋值运算符函数，实现深拷贝。
    {
        delete[] items;           // 释放原内存。
        len = v.len;                // 数组实际的大小。
        items = new T1[len];  // 重新分配数组。
        for (int ii = 0; ii < len; ii++) items[ii] = v.items[ii];    // 复制数组中的元素。
        return *this;
    }

    void resize(int size) {         // 护展数组的内存空间。
        if (size <= len) return;   // 只能往更大扩展。
        T1 *tmp = new T1[size];   // 分配更大的内存空间。
        for (int ii = 0; ii < len; ii++) tmp[ii] = items[ii];     // 把原来数组中的元素复制到新数组。
        delete[] items;    // 释放原来的数组。
        items = tmp;      // 让数组指针指向新数组。
        len = size;           // 扩展后的数组长度。
    }

    int size() const { return len; }     // 获取数组长度。
    T1 &operator[](int ii) {   // 重载操作符[]，可以修改数组中的元素。
        if (ii >= len) resize(ii + 1);    // 扩展数组。
        return items[ii];
    }

    const T1 &operator[](int ii) const { return items[ii]; }  // 重载操作符[]，不能修改数组中的元素。
};

void joint_and_recursive_use_of_templates() {
    cout << endl << "========================joint_and_recursive_use_of_templates========================" << endl;

    // Vector1容器的大小缺省值是2，Stack1容器的大小缺省值是3。
    // 创建Vector1容器，容器中的元素用Stack1<string>。
    Vector1<Stack1<string>> vs;         // C++11之前，>>之间要加空格。

    // 手工的往容器中插入数据。
    vs[0].push("西施1");
    vs[0].push("西施2");
    vs[0].push("西施3");        // vs容器中的第0个栈。
    vs[1].push("西瓜1");
    vs[1].push("西瓜2");
    vs[1].push("西瓜3");        // vs容器中的第1个栈。
    vs[2].push("冰冰");
    vs[2].push("幂幂");                                            // vs容器中的第2个栈。

    // 用嵌套的循环，把vs容器中的数据显示出来。
    for (int ii = 0; ii < vs.size(); ii++)         // 遍历Vector1容器。
    {
        while (vs[ii].isempty() == false)      // 遍历Stack1容器。
        {
            string item;
            vs[ii].pop(item);
            cout << "item = " << item << endl;
        }
    }

    // 创建Stack1容器，容器中的元素用Vector1<string>。
    Stack1<Vector1<string>> sv;

    Vector1<string> tmp;       // 栈的元素，临时Vector1<string>容器。
    // 第一个入栈的元素。
    tmp[0] = "西施1";
    tmp[1] = "西施2";
    sv.push(tmp);
    // 第二个入栈的元素。
    tmp[0] = "西瓜1";
    tmp[1] = "西瓜2";
    sv.push(tmp);
    // 第三个入栈的元素。
    tmp[0] = "冰冰1";
    tmp[1] = "冰冰2";
    tmp[2] = "冰冰3";
    tmp[3] = "冰冰4";
    sv.push(tmp);

    // 用嵌套的循环，把sv容器中的数据显示出来。
    while (sv.isempty() == false) {
        sv.pop(tmp);   // 出栈一个元素，放在临时容器中。
        for (int ii = 0; ii < tmp.size(); ii++)   // 遍历临时Vector1<string>容器，显示容器中每个元素的值。
            cout << " vs[" << ii << "] = " << tmp[ii] << endl;
    }

    // 创建Vector1容器，容器中的元素用Vector1<string>。
    Vector1<Vector1<string>> vv;       // 递归使用模板类。

    vv[0][0] = "西施1";
    vv[0][1] = "西施2";
    vv[0][2] = "西施3";
    vv[1][0] = "西瓜1";
    vv[1][1] = "西瓜2";
    vv[2][0] = "冰冰1";
    vv[2][1] = "冰冰2";
    vv[2][2] = "冰冰3";
    vv[2][3] = "冰冰4";

    // 用嵌套的循环，把vv容器中的数据显示出来。
    for (int ii = 0; ii < vv.size(); ii++) {
        for (int jj = 0; jj < vv[ii].size(); jj++)
            // cout << " vv[" << ii << "][" << jj << "] = " << vv[ii][jj] << endl;
            cout << vv[ii][jj] << " ";
        cout << endl;
    }

    cout << endl << "========================joint_and_recursive_use_of_templates========================" << endl;
}