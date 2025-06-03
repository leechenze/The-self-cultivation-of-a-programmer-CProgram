//
// Created by Lee ChenZe on 6/3/25.
//
#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

// 普通函数
void show1(int bh, const string& message) {
    cout << "亲爱的" << bh << "，" << message << endl;
}

struct AA	// 类中有静态成员函数。
{
    static void show1(int bh, const string& message) {
        cout << "亲爱的" << bh << "，" << message << endl;
    }
};

struct BB	// 仿函数。
{
    void operator()(int bh, const string& message) {
        cout << "亲爱的" << bh << "，" << message << endl;
    }
};

struct CC	// 类中有普通成员函数。
{
    void show1(int bh, const string& message) {
        cout << "亲爱的" << bh << "，" << message << endl;
    }
};

struct DD		// 可以被转换为普通函数指针的类。
{
    using Fun = void (*)(int, const string&);    // 函数指针的别名。
    operator Fun() {
        return show1;	// 返回普通函数show1的地址。
    }
};

void wrapper_function() {
    cout << endl << "========================wrapper_function========================" << endl;

    using Fun = void(int, const string&);  // 函数类型的别名。

    // 普通函数。
    // void(*fp1)(int, const string&) = show1;	// 声明函数指针，指向函数对象。
    // fp1(1, "我是一只傻傻鸟。");						// 用函数指针调用普通函数。
    // function<void(int, const string&)> fn1 = show1;    // 包装普通全局函数show1。
    // fn1(1, "我是一只傻傻鸟。");										// 用function对象调用普通全局函数show1。

    // 类的静态成员函数。
    // void(*fp3)(int, const string&) = AA::show1;	// 用函数指针指向类的静态成员函数。
    // fp3(2, "我是一只傻傻鸟。");							// 用函数指针调用类的静态成员函数。
    // function<void(int, const string&)> fn3 = AA::show1;		// 包装类的静态成员函数。
    // fn3(2, "我是一只傻傻鸟。");												// 用function对象调用类的静态成员函数。

    // 仿函数。
    // BB bb;
    // bb(3, "我是一只傻傻鸟。");		// 用仿函数对象调用仿函数。
    // function<void(int, const string&)> fn4 = BB();		// 包装仿函数。
    // fn4(3, "我是一只傻傻鸟。");										// 用function对象调用仿函数。

    // 创建lambda对象。
    // auto lb = [](int bh, const string& message) {
    //     cout << "亲爱的" << bh << "，" << message << endl;
    // };
    // lb(4, "我是一只傻傻鸟。");          // 调用lambda函数。
    // function<void(int, const string&)> fn5 = lb;			// 包装lamba函数。
    // fn5(4, "我是一只傻傻鸟。");										// 用function对象调用lamba函数。

    // 类的非静态成员函数。
    // CC cc;
    // void (CC:: * fp11)(int, const string&) = &CC::show1;		// 定义类成员函数的指针。
    // (cc.*fp11)(5, "我是一只傻傻鸟。");									// 用类成员函数的指针调用类的成员函数。
    // function<void(CC&,int, const string&)> fn11 = &CC::show1;	// 包装成员函数。
    // fn11(cc,5, "我是一只傻傻鸟。");											// 用function对象调用成员函数。

    // 可以被转换为函数指针的类对象。
    // DD dd;
    // dd(6, "我是一只傻傻鸟。");						// 用可以被转换为函数指针的类对象调用普通函数。
    // function<void(int, const string&)> fn12 = dd;			// 包装可以被转换为函数指针的类。
    // fn12(6, "我是一只傻傻鸟。");										// 用function对象调用它。

    // 如果std::function对象未包装可调用对象，使用std::function对象将抛出std::bad_function_call异常。
    // 可以做个if判断 if (fx) 也可以避免异常
    // function<void(int, const string&)> fx=dd;
    // try {
    //     if (fx) fx(6, "我是一只傻傻鸟。");
    // }
    // catch (std::bad_function_call e) {
    //     cout << "抛出了std::bad_function_call异常。";
    // }

    cout << endl << "========================wrapper_function========================" << endl;
}
