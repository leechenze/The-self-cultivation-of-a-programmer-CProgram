//
// Created by Lee ChenZe on 1/11/24.
//

#include <iostream>

using namespace std;


class Person8 {
public:
    // 编号
    int identifier;
    char name[3];
    static int age;

    Person8() {
        memset(name, 0, sizeof(name));
        age = 0;
    }

    ~Person8() {}

    void showName() {
        // 判断this指针是否为空，避免程序崩溃
        if (this == nullptr) {
            cout << "The program has exited" << endl;
            return;
        }
        cout << "姓名：" << this->name << endl;
    }

    void showAge() {
        cout << "年龄：" << age << endl;
    }

    void showFixedVal() {
        cout << "roosevelt" << endl;
    }

};

int Person8::age;
int aaa;

void testFunc() {}

void simple_object_model() {

    cout << endl;

    Person8 person81;
    cout << "对象person81占有的内存大小是：" << sizeof(person81) << endl;
    cout << "对象person81的地址是：" << &person81 << endl;
    cout << "成员变量identifier的地址是：" << (void *) &person81.identifier << endl;
    cout << "成员变量name的地址是：" << (void *) &person81.name << endl;
    cout << "成员变量age的地址是：" << (void *) &person81.age << endl;
    cout << "全局变量变量aaa的地址是：" << (void *) &aaa << endl;
    printf("成员函数showname的地址是：%p\n", &Person8::showName);
    printf("成员函数showage的地址是：%p\n", &Person8::showAge);
    printf("普通函数testFunc的地址是：%p\n", &testFunc);

    Person8 *person82 = nullptr;
    person82->showFixedVal();
    person82->showName();


    cout << endl << endl << "==================simple_object_model==================" << endl;
}