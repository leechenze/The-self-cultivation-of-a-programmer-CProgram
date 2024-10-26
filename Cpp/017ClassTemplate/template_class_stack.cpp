//
// Created by Lee ChenZe on 10/26/24.
//

#include <iostream>

using namespace std;

// 定义栈元素的数据类型
typedef int DateType;

template<class DateType>
class Stack {
private:
    // 栈数组
    DateType *items;
    // 栈实际大小
    int stacksize;
    // 栈顶指针(不是cpp中的指针,而是一个位置指针)
    int top;
public:
    Stack(int size) : stacksize(size), top(0) {
        items = new DateType[stacksize];
    }

    ~Stack() {
        delete[]items;
        items = nullptr;
    }

    // 判断栈是否为空
    bool isEmpty() const {
        return top == 0;
    }

    // 判断栈是否已满
    bool isFull() const {
        return top == stacksize;
    }

    // 元素入栈
    bool push(const DateType &item) {
        if (top < stacksize) {
            items[top++] = item;
            return true;
        }
        return false;
    }

    // 元素出栈
    bool pop(DateType &item) {
        if (top > 0) {
            item = items[--top];
            return true;
        }
        return false;
    }
};

void template_class_stack() {
    cout << endl << "========================template_class_stack========================" << endl;

    Stack<DateType> ss(5);

    // 元素入栈
    ss.push(1);
    ss.push(2);
    ss.push(3);
    ss.push(4);
    ss.push(5);
    // 元素出栈
    DateType item;
    while (ss.isEmpty() == false) {
        ss.pop(item);
        cout << "item = " << item << endl;
    }

    cout << endl << "========================template_class_stack========================" << endl;
}