//
// Created by Lee ChenZe on 1/10/24.
//


#include <iostream>

using namespace std;

class Person6 {
public:
    string name;
    int appearance;

    Person6(const string newName, int newAppearance) {
        name = newName;
        appearance = newAppearance;
    }

    void show() const {
        cout << "我是：" << name << ", 颜值更高" << endl;
    }

    const Person6 &compare(const Person6 &person) const {
        if (person.appearance > appearance) {
            return person;
        } else {
            return *this;
        }
    }

    // 每个成员函数（包括构造函数和析构函数）都有一个this指针，可以用它访问调用者对象的成员。
    int aa;

    void func(int aa) {
        this->aa = aa;
    }

};


const Person6 &compare(const Person6 person1, const Person6 person2) {
    if (person1.appearance > person2.appearance) { return person1; }
    else { return person2; }
}

void this_point() {

    cout << endl;

    // 需求：比较两个人的颜值，然后由更漂亮的人做自我介绍；
    Person6 person61("steven", 10),
            person62("stephen", 20),
            person63("roosevelt", 30),
            person64("abraham", 40),
            person65("thomas", 25);

    // const Person6 &winPerson = compare(person61, person62);
    // winPerson.show();

    // const Person6 &winPerson1 = person61.compare(person62);
    // winPerson1.show();

    const Person6 &mulWinPerson1 = person61.compare(person62)
            .compare(person63)
            .compare(person64)
            .compare(person65);
    mulWinPerson1.show();


    cout << endl << endl << "==================this_point==================" << endl;
}