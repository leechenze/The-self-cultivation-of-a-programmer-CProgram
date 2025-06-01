//
// Created by Lee ChenZe on 6/1/25.
//
#define _CRT_SECURE_NO_WARNINGS  // localtime()需要这个宏。
#include <iostream>
#include <chrono>
#include <iomanip>   // put_time()函数需要包含的头文件。
#include <sstream>
using namespace std;

using namespace std;


void chrono_time_operation_library() {
    cout << endl << "========================chrono_time_operation_library========================" << endl;


    cout << endl << "========================时间长度========================" << endl;

    // 1小时
    chrono::hours  t1(1);
    //  60分钟
    chrono::minutes  t2(60);
    //  60*60秒
    chrono::seconds  t3(60 * 60);
    // 60*60*1000毫秒
    chrono::milliseconds  t4(60 * 60 * 1000);
    // 警告：整数溢出。
    chrono::microseconds t5(60 * 60 * 1000 * 1000);
    // 警告：整数溢出。
    chrono::nanoseconds t6(60 * 60 * 1000 * 1000*1000);

    if (t1 == t2)    cout << "t1==t2\n";
    if (t1 == t3)    cout << "t1==t3\n";
    if (t1 == t4)    cout << "t1==t4\n";

    // 获取时钟周期的值，返回的是int整数。
    cout << "t1=" << t1.count() << endl;
    cout << "t2=" << t2.count() << endl;
    cout << "t3=" << t3.count() << endl;
    cout << "t4=" << t4.count() << endl;

    // 1秒
    chrono::seconds t7(1);
    // 1000毫秒
    chrono::milliseconds  t8(1000);
    // 1000*1000微秒
    chrono::microseconds t9(1000 * 1000);
    //  1000*1000*1000纳秒
    chrono::nanoseconds t10(1000 * 1000 * 1000);

    if (t7 == t8)    cout << "t7==t8\n";
    if (t7 == t9)    cout << "t7==t9\n";
    if (t7 == t10)  cout << "t7==t10\n";

    // 获取时钟周期的值。
    cout << "t7=" << t7.count() << endl;
    cout << "t8=" << t8.count() << endl;
    cout << "t9=" << t9.count() << endl;
    cout << "t10=" << t10.count() << endl;


    cout << endl << "========================系统时间========================" << endl;

    // 1）静态成员函数chrono::system_clock::now()用于获取系统时间。（C++时间）
    auto now = chrono::system_clock::now();

    // 2）静态成员函数chrono::system_clock::to_time_t()把系统时间转换为time_t。（UTC时间）
    auto t_now = chrono::system_clock::to_time_t(now);

    // t_now = t_now + 24*60*60;   // 把当前时间加1天。
    // t_now = t_now + -1*60*60;   // 把当前时间减1小时。
    // t_now = t_now + 120;           // 把当前时间加120秒。

    // 3）std::localtime()函数把time_t转换成本地时间。（北京时）
    // localtime()不是线程安全的，VS用localtime_s()代替，Linux用localtime_r()代替。
    auto tm_now = std::localtime(&t_now);

    // 4）格式化输出tm结构体中的成员。
    std::cout << std::put_time(tm_now, "%Y-%m-%d %H:%M:%S") << std::endl;
    std::cout << std::put_time(tm_now, "%Y-%m-%d") << std::endl;
    std::cout << std::put_time(tm_now, "%H:%M:%S") << std::endl;
    std::cout << std::put_time(tm_now, "%Y%m%d%H%M%S") << std::endl;

    stringstream ss;   // 创建stringstream对象ss，需要包含<sstream>头文件。
    ss << std::put_time(tm_now, "%Y-%m-%d %H:%M:%S");    // 把时间输出到对象ss中。
    string timestr = ss.str();     // 把ss转换成string的对象。
    cout << timestr << endl;

    cout << endl << "========================计时器========================" << endl;

    // 静态成员函数chrono::steady_clock::now()获取开始的时间点。
    auto start = chrono::steady_clock::now();

    // 执行一些代码，让它消耗一些时间。
    cout << "计时开始 ...... \n";
    for (int ii = 0; ii < 1000000000; ii++) {
        // cout << "我是一只傻傻鸟。\n";
    }
    cout << "计时完成 ...... \n";

    // 静态成员函数chrono::steady_clock::now()获取结束的时间点。
    auto end = chrono::steady_clock::now();

    // 计算消耗的时间，单位是纳秒。
    auto dt = end - start;
    cout << "耗时: " << dt.count() << "纳秒（"<<(double)dt.count()/(1000*1000*1000)<<"秒）";


    cout << endl << "========================chrono_time_operation_library========================" << endl;
}
