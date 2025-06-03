//
// Created by Lee ChenZe on 6/3/25.
//

#include <iostream>
#include <thread>
#include <chrono>

using namespace std;


// 普通函数
void show2(int bh, const string& message) {
    cout << "亲爱的" << bh << "号，" << message << endl;
}

void binder_bind() {
    cout << endl << "========================binder_bind========================" << endl;

    function<void(int, const string&)> fn1 = show2;
    function<void(int, const string&)> fn2 = bind(show2, placeholders::_1, placeholders::_2);
    fn1(1, "我是一只傻傻鸟。");
    fn2(1, "我是一只傻傻鸟。");

    function<void(const string&, int)> fn3 = bind(show2, placeholders::_2, placeholders::_1);
    // fn3("我是一只傻傻鸟。", 1);
    // function<void(const string&)> fn4 = bind(show2, 3, placeholders::_1);
    // fn4("我是一只傻傻鸟。");
    /** 如果要传递引用可以用 std::ref()包裹 */
    // int bh = 3;
    // function<void(const string&)> fn4 = bind(show2, ref(bh), placeholders::_1);
    // bh = 8;
    // fn4("我是一只傻傻鸟。");

    cout << endl << "========================binder_bind========================" << endl;
}
