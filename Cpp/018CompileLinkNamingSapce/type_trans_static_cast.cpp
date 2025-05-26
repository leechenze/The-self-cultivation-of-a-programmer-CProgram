//
// Created by Lee ChenZe on 5/26/25.
//

#include <iostream>;

using namespace std;

void func(void* ptr) {
    long long ii = reinterpret_cast<long long>(ptr);
    cout << "ii = " << ii << endl;
}


void type_trans_static_cast() {
    cout << endl << "========================type_trans_static_cast========================" << endl;

    /**
     * 内置数据类型之间的转换
     */
    // int ii = 3;
    // // 绝对安全的，可以隐式转换，不会出现警告
    // long ll = ii;
    //
    // double dd = 123;
    // // 可以隐式转换, 但是可能会出现精度丢失的问题
    // long ll1 = dd;
    // // C风格, 显示转换, 不会出现警告.
    // long ll2 = (long)dd;
    // // Cpp风格, 显示转换, 不会出现警告.
    // long ll3 = static_cast<long>(dd);

    /**
     * 指针之间的转换
     */
    int ii = 10;
    // 错误, 不能隐式转换.
    // double* pd1 = &ii;
    // C风格, 强制转换
    double* pd1 = (double*)&ii;
    // Cpp风格, 强制转换
    // 首先转换void指针, 任何类型的指针都可以隐式转换成void指针;
    void* pv = &ii;
    // 再次转换double指针, static_cast可以把void指针转换为其他类型指针.
    double* pd2 = static_cast<double*>(pv);

    /**
     * reinterpret_ca的指针类型的转换
     */
     long long ll = 10;
     func(reinterpret_cast<void*>(ll));

    /**
     * const_cast的指针类型的转换
     */
    const int *aa = nullptr;
    // C风格, 强制转换, 丢掉const限定符
    int *bb = (int*) aa;
    // Cpp风格, 强制转换, 丢掉const限定符
    int *cc = const_cast<int*>(aa);

    cout << endl << "========================type_trans_static_cast========================" << endl;
}