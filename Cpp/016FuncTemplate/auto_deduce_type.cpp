//
// Created by Lee ChenZe on 10/8/24.
//
#include <iostream>

using namespace std;

double func(double b, const char *c, float d, short e, long f) {
    cout << "b=" << b << ",c=" << c << ",d=" << d << ",e=" << e << ",f=" << f << endl;
    return 5.5;
}

void auto_deduce_type() {
    cout << endl << "========================auto_deduce_type========================" << endl;


    double (*pf)(double, const char *, float, short, long);    // 声明函数指针pf。
    pf = func;
    pf(2, "西施", 3, 4, 5);
    auto pf1 = func;
    pf1(2, "西施", 3, 4, 5);


    cout << endl << "========================auto_deduce_type========================" << endl;
}