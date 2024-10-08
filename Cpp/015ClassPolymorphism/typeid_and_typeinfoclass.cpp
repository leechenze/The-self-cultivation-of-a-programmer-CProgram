//
// Created by Lee ChenZe on 10/8/24.
//

#include <stdio.h>
#include <iostream>
#include <string>
#include <typeinfo>

using namespace std;

class AA2 {   // 定义一个类。
public:
    AA2() {}
};


void typeid_and_typeinfoclass() {
    cout << endl << "========================typeid_and_typeinfoclass========================" << endl;

    // typeid用于Cpp内置的数据类型
    int ii = 3;
    int *pii = &ii;
    int &rii = ii;
    cout << "typeid(int) = " << typeid(int).name() << endl;
    cout << "typeid(ii) = " << typeid(ii).name() << endl;
    cout << "typeid(int *) = " << typeid(int *).name() << endl;
    cout << "typeid(pii) = " << typeid(pii).name() << endl;
    cout << "typeid(int &) = " << typeid(int &).name() << endl;
    cout << "typeid(rii) = " << typeid(rii).name() << endl;
    cout << endl;

    // typeid用于自定义的数据类型。
    AA2 aa;
    AA2 *paa = &aa;
    AA2 &raa = aa;
    cout << "typeid(AA2)= " << typeid(AA2).name() << endl;
    cout << "typeid(aa)= " << typeid(aa).name() << endl;
    cout << "typeid(AA2 *)= " << typeid(AA2 *).name() << endl;
    cout << "typeid(paa)= " << typeid(paa).name() << endl;
    cout << "typeid(AA2 &)= " << typeid(AA2 &).name() << endl;
    cout << "typeid(raa)= " << typeid(raa).name() << endl;
    cout << endl;

    // type_info重载了==和!=运算符，用于对类型进行比较。
    if (typeid(AA2) == typeid(aa)) cout << "ok1\n";
    if (typeid(AA2) == typeid(*paa)) cout << "ok2\n";
    if (typeid(AA2) == typeid(raa)) cout << "ok3\n";
    if (typeid(AA2 *) == typeid(paa)) cout << "ok4\n";


    cout << endl << "========================typeid_and_typeinfoclass========================" << endl;
}