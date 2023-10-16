//
// Created by Lee ChenZe on 10/16/23.
//


#include <iostream>

using namespace std;

class Person4 {
public:
    string name;
    int age;

    // 构造函数的初始化列表
    Person4() : name("Franklin"), age(33) {
        cout << "调用了Person4()构造函数" << endl;
    }

    // 初始化列表的括号中可以是具体的值，也可以是构造函数的形参名，还可以是表达式。
    Person4(string newName, int newAge) : name(newName), age(newAge) {
        // name = newName;
        // age = newAge;
        cout << "调用了Person4(string newName, int newAge)构造函数" << endl;
    }

    void show() { cout << "姓名：" << name << "，年龄：" << age << endl; }

};

void initializer_cuslist() {
    cout << endl;

    Person4 person41;
    Person4 person42("Roosevelt", 22);
    person41.show();
    person42.show();

    cout << endl << endl << "==================initializer_cuslist==================" << endl;
}
