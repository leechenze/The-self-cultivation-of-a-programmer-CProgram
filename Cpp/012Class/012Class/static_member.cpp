//
// Created by Lee ChenZe on 1/10/24.
//

#include <iostream>

using namespace std;


class Person7 {
public:
    string name;
    static int age;

    Person7(const string &newName, int newAge) {
        name = newName;
        age = newAge;
    }

    // 显示姓名
    void showName() {
        cout << "姓名：" << name << endl;
    }

    // 显示年龄
    static void showAge() {
        cout << "年龄：" << age << endl;
    }
};

// 静态成员必须在全局赋初始值，否则报错；
int Person7::age = 8;

void static_member() {

    cout << endl;

    cout << "Person7::age: " << Person7::age << endl;
    cout << "Person7::showAge(): ";
    Person7::showAge();
    cout << endl;

    Person7 person70("roosevelt", 20);
    person70.showName();
    person70.showAge();

    cout << endl << endl << "==================static_member==================" << endl;
}