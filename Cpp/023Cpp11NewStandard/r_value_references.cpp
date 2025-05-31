//
// Created by Lee ChenZe on 5/31/25.
//
#include <iostream>;
#include <string>;

using namespace std;


void r_value_references() {
    cout << endl << "========================r_value_references========================" << endl;
    
    // TODO
    // getTemp()的返回值本来在表达式语句结束后其生命也就该终结了（因为是临时变量），而通过右值引用重获了新生，其生命周期将与右值引用类型变量aa的生命周期一样，只要aa还活着，该右值临时变量将会一直存活下去。

    cout << endl << "========================r_value_references========================" << endl;
}
