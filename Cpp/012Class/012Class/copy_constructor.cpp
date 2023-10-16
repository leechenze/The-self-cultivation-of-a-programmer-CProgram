//
//  copy_constructor.cpp
//  012Class
//
//  Created by Lee ChenZe on 9/4/23.
//

#include <iostream>

using namespace std;

class Person2 {
public:
    string name;
    int age;

    // 构造函数
    Person2() {
        name.clear();
        age = 0;
        cout << "调用了Person2构造函数" << endl;
    }

    // 析构函数
    ~Person2() {
        cout << "调用了~Person2析构函数" << endl;
    }

    // 没有重载的拷贝构造函数
    // 如果类中定义了拷贝构造函数，编译器将不提供默认的拷贝构造函数。
    // Person2(const Person2 &person) {
    //     name = "漂亮的" + person.name;
    //     age = person.age - 5;
    //     cout << "调用了Person2(const Person2 &person)拷贝构造函数" << endl;
    // }

    // 自我介绍方法，显示姓名和年龄
    void show() {
        cout << "姓名：" << name << ", 年龄：" << age << endl;
    }
};

class Person3 {
public:
    string name;
    int age;
    // 指针成员，深拷贝用
    int *ptr;

    // 构造函数
    Person3() {
        name.clear();
        age = 0;
        ptr = new int;
        cout << "调用了Person3构造函数" << endl;
    }

    // 深拷贝
    Person3(const Person3 &person) {
        name = person.name;
        age = person.age;
        // 分配内存
        ptr = new int;
        // 基础数据拷贝
        // *ptr = *person.ptr;
        // 复杂数据拷贝
        memcpy(ptr, person.ptr, sizeof(int));
        cout << "调用了Person3(const Person3 &person)深拷贝构造函数" << endl;
    }

    void show() {
        cout << "姓名：" << name << ", 年龄：" << age << "，ptr=" << ptr << "，*ptr=" << *ptr << endl;
    }
};

// 以值传递的方式调用函数时，如果实参为对象，会调用拷贝构造函数。
void func(Person2 person) {
    person.show();
}


void copy_constructor() {
    cout << endl;

    Person2 person21;
    Person2 person22 = Person2();
    Person2 *person23 = new Person2;
    Person2 *person24 = new Person2();
    Person3 person31;
    delete person23;
    delete person24;

    person21.name = "clinton";
    person21.age = 30;
    person22.name = "Franklin";
    person22.age = 40;
    person31.name = "Roosevelt";
    person31.age = 45;
    person31.ptr = new int(3);

    cout << endl;

    // 用已存在的对象创建新的对象的语法
    Person2 person221(person21);
    Person2 person222 = person22;
    person221.show();
    person222.show();

    cout << endl;
    func(person21);

    cout << "深拷贝" << endl;
    Person3 person311(person31);
    *person311.ptr = 8;
    person311.show();
    person31.show();

    cout << endl << endl << "==================copy_constructor==================" << endl;
}
