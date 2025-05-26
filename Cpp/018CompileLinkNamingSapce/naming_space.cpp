//
// Created by Lee ChenZe on 5/23/25.
//

#include <iostream>;

using namespace std;

namespace aa {
    int ab = 11;
    void func();
    class A1{
    public:
        void show();
    };
    void func() {
        cout << "func被调用了" << endl;
    }
    void A1::show() {
        cout << "A1::show被调用了" << endl;
    }
}


void naming_space() {
    cout << endl << "========================naming_space========================" << endl;

    // 方法二:
    // using aa::ab;
    // 方法三:
    using namespace aa;

    // 方法一:
    cout << "ab = " << aa::ab << endl;
    aa::func();
    aa::A1 a;
    a.show();
    cout << "ab = " << ab << endl;

    // 方法二:
    cout << "ab = " << ab << endl;
    func();
    A1 a1;
    a1.show();
    int ab = 22;
    cout << "ab = " << ab << endl;


    cout << endl << "========================naming_space========================" << endl;
}