//
// Created by Lee ChenZe on 5/31/25.
//
#include <iostream>;
#include <string>;

using namespace std;

class AA {
public:
    int m_a=9;
};

AA getTemp() {
    return AA();
}

void r_value_references() {
    cout << endl << "========================r_value_references========================" << endl;

    // 3是右值。
    int&& a = 3;
    // b是左值。
    int b = 8;
    //  b+5是右值。
    int&& c = b + 5;

    // getTemp()的返回值是右值（临时变量）。
    AA&& aa = getTemp();

    cout << "a=" << a << endl;
    cout << "c=" << c << endl;
    cout << "aa.m_a=" << aa.m_a << endl;
    // getTemp()的返回值本来在表达式语句结束后其生命也就该终结了（因为是临时变量），而通过右值引用重获了新生，其生命周期将与右值引用类型变量aa的生命周期一样，只要aa还活着，该右值临时变量将会一直存活下去。


    cout << endl << "========================r_value_references========================" << endl;
}
