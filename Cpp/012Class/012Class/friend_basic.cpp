//
// Created by Lee ChenZe on 1/12/24.
//

//
// Created by Lee ChenZe on 1/11/24.
//

#include <iostream>

using namespace std;

class Person9 {
    // 设置全局友元函数
    friend void friend_basic();

    // 设置友元类
    friend class Person10;

public:
    string name = "abraham";

    Person9() {

    }

    void showName() {
        cout << "姓名: " << name << endl;
    }

private:
    int height = 169;

    void showHeight() {
        cout << "身高: " << height << endl;
    }
};

class Person10 {
public:
    void showOtherHeight(Person9 &p9) {
        cout << "Person9的姓名是" << p9.name << endl;
        cout << "Person9的身高是" << p9.height << endl;
        p9.showHeight();
    }
};


void friend_basic() {

    cout << endl;

    Person9 person91;
    person91.showName();
    person91.showHeight();

    Person10 person101;
    person101.showOtherHeight(person91);

    cout << endl << endl << "==================friend_basic==================" << endl;
}