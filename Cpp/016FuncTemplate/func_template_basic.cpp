//
// Created by Lee ChenZe on 10/8/24.
//

#include <iostream>

using namespace std;


template<typename T>
void swapHandler(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;

}

void func_template_basic() {
    cout << endl << "========================func_template_basic========================" << endl;

    int a = 0, b = 10;
    swapHandler(a, b);
    // swapHandler<int>(a, b);
    cout << "a = " << a << ", b = " << b << endl;

    cout << endl << "========================func_template_basic========================" << endl;
}