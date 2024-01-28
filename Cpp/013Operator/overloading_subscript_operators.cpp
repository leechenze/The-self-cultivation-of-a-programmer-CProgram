//
// Created by Lee ChenZe on 1/27/24.
//


#include <iostream>

using namespace std;


class CGirl1 {
private:
    string boys[3];
public:
    string name;

    CGirl1() {
        boys[0] = "Abraham";
        boys[1] = "Roosevelt";
        boys[2] = "MarcoPolo";
    }

    void showAllBoys() {
        cout << boys[0] << "、" << boys[1] << "、" << boys[2] << endl;
    }

    string showBoy(int i) {
        return boys[i];
    }

    // 如果返回的是引用，那么函数调用的表达式就可以当成变量一样使用，那么就可以修改该引用的值
    // 如：g.showBoyRef(0) = "Douglas";
    string &showBoyRef(int i) {
        return boys[i];
    }

    // 以上方式可以实现，但是代码很奇怪，更好的方式是重载下标运算符
    // 写法：g[0] = "Douglas";
    string &operator[](int i) {
        return boys[i];
    }

    // 提供常函数的写法，用于常对象g1访问时使用。
    const string &operator[](int i) const {
        return boys[i];
    }
};


void overloading_subscript_operators() {

    cout << endl;

    CGirl1 g;
    g.showAllBoys();
    // g.showBoyRef(0) = "Douglas";
    g[0] = "Douglas";
    cout << "the first boyfriend is " << /* g.showBoy(0) */ g[0] << endl;

    const CGirl1 g1 = g;
    cout << "the first boyfriend is " << g1[0] << endl;

    cout << endl << endl << "==================overloading_subscript_operators==================" << endl;
}