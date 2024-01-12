//
// Created by Lee ChenZe on 1/10/24.
//


#include <iostream>

using namespace std;

class Person5 {
public:
    mutable string name;
    int age;

    Person5(const string &newName, int newAge) {
        name = newName;
        age = newAge;
        cout << "调用了Person5(newName, newAge)构造函数" << endl;
    }

    // 在类的成员函数后面加const关键字，表示在成员函数中保证不会修改调用对象的成员变量。
    void show() const {
        name = "cliton";
        cout << "姓名：" << name << "，年龄：" << age << endl;
        show1();
        // show2();
    }

    void show1() const {
        name = "cliton";
        cout << "姓名：" << name << "，年龄：" << age << endl;
    }

    void show2() {
        name = "cliton";
        cout << "姓名：" << name << "，年龄：" << age << endl;
        show();
        show3();
    }

    void show3() {
        name = "cliton";
        cout << "姓名：" << name << "，年龄：" << age << endl;
    }

};


void const_decorate_func() {
    cout << endl;

    Person5 person5("Roosevelt", 33);
    person5.show();

    // const 修饰的对象只能调用const修饰的成员函数
    const Person5 person51("Roosevelt", 33);
    person51.show1();

    cout << endl << endl << "==================const_decorate_func==================" << endl;
}