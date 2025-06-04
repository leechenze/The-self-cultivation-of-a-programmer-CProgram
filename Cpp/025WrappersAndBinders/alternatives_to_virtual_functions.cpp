//
// Created by Lee ChenZe on 6/4/25.
//
#include <iostream>
#include <functional>
using namespace std;

struct Animal {  // 动物基类
    function<void()> m_speak;  // 用于绑定子类的说话函数

    // 注册子类成员函数（无参数）
    template<typename Fn, typename ...Args>
    void callback(Fn&& fn, Args&&...args) {
        m_speak = bind(forward<Fn>(fn), forward<Args>(args)...);
    }

    void speak() {  // 实际调用绑定的子类函数
        if (m_speak) m_speak();
    }
};

struct Cat : public Animal {
    void speak() {
        cout << "🐱 小猫喵喵叫~" << endl;
    }
};

struct Dog : public Animal {
    void speak() {
        cout << "🐶 小狗汪汪叫~" << endl;
    }
};


void alternatives_to_virtual_functions() {
    cout << endl << "========================alternatives_to_virtual_functions========================" << endl;

    int id = 0;
    cout << "请选择动物：1-猫，2-狗 ：";
    cin >> id;

    Animal* animal = nullptr;

    if (id == 1) {
        animal = new Cat;
        animal->callback(&Cat::speak, (Cat*)animal);
        // animal->callback(&Cat::speak, static_cast<Cat*>(animal));
    } else if (id == 2) {
        animal = new Dog;
        animal->callback(&Dog::speak, static_cast<Dog*>(animal));
    }

    if (animal != nullptr) {
        animal->speak();  // 调用实际的子类speak函数
        delete animal;
    }

    cout << endl << "========================alternatives_to_virtual_functions========================" << endl;
}
