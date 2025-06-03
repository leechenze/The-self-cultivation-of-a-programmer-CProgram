//
// Created by Lee ChenZe on 6/3/25.
//
#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

/**
 * 函数声明
 */
// 普通函数类型的别名
using Fun = void(int, const string &);
// 声明普通函数
// Fun show;
// 等同于
// void show(int, const string &);


/**
 * 定义普通函数
 */
void show(int bh, const string& str){
    cout << "定义普通函数: " << bh << ", " << str << endl;
}
/**
 * 定义仿函数
 * 这里不用class，而用结构体定义是因为懒得写public的声明了，结构体就是类，类就是结构体，只是访问权限的不同罢了
 */
struct BB	// 仿函数。
{
    void operator()(int bh, const string& message) {
        cout << "亲爱的" << bh << "，" << message << endl;
    }
};
/**
 * 类的普通成员函数
 * 这里不用class，而用结构体定义是因为懒得写public的声明了，结构体就是类，类就是结构体，只是访问权限的不同罢了
 */
struct CC	// 类中有普通成员函数。
{
    void show(int bh, const string& message) {
        cout << "亲爱的" << bh << "，" << message << endl;
    }
};


void callable_objects() {
    cout << endl << "========================callable_objects========================" << endl;

    /**
     * 注意这里只列举了三个，其他的语法，含义都相同，请在课件中看。
     */

    cout << endl << "========================普通函数========================" << endl;

    // 普通函数的调用
    show(1, "I'm bryant");
    void(*fp1)(int, const string&) = show;	// 声明函数指针，指向普通函数。
    void(&fr1)(int, const string&) = show;	// 声明函数引用，引用普通函数。
    fp1(2, "我是一只傻傻鸟。");						// 用函数指针调用普通函数。
    fr1(3, "我是一只傻傻鸟。");						// 用函数引用调用普通函数。

    Fun* fp2 = show;										// 声明函数指针，指向普通函数。
    Fun& fr2 = show;									// 声明函数引用，引用普通函数。
    fp2(4, "我是一只傻傻鸟。");						// 用函数指针调用普通函数。
    fr2(5, "我是一只傻傻鸟。");						// 用函数引用调用普通函数。


    cout << endl << "========================仿函数========================" << endl;

    BB bb;
    bb(11, "我是一只傻傻鸟。");		// 用对象调用仿函数。
    BB()(12, "我是一只傻傻鸟。");		// 用匿名对象调用仿函数。

    BB& br = bb;           		// 引用函数
    br(13, "我是一只傻傻鸟。");		// 用对象的引用调用仿函数。


    cout << endl << "========================类的非静态成员函数========================" << endl;

    CC cc;
    cc.show(14, "我是一只傻傻鸟。");

    void (CC::* fp11)(int, const string&) = &CC::show;		// 定义类的成员函数的指针。
    (cc.*fp11)(15, "我是一只傻傻鸟。");									// 用类的成员函数的指针调用成员函数。

    using pFun = void (CC::*)(int, const string&);		// 类成员函数的指针类型。
    pFun fp12 = &CC::show;										// 让类成员函数的指针指向类的成员函数的地址。
    (cc.*fp12)(16, "我是一只傻傻鸟。");							// 用类成员函数的指针调用类的成员函数。


    cout << endl << "========================callable_objects========================" << endl;
}
