//
// Created by Lee ChenZe on 10/22/24.
//

#include <iostream>

using namespace std;

class CGirl {
public:
    template<typename T>
    CGirl(T a) {
        cout << "a = " << a << endl;
    }

    template<typename T>
    void show(T b) {
        cout << "b = " << b << endl;
    }
};

template<typename T1, typename T2>
void show(T1 no, T2 message) {
    cout << "亲爱的" << no << "号:" << message << endl;
}


// =============================================
template<typename T>
void func(T a) {
    cout << "func(T a)" << endl;
}

template<typename T1, typename T2>
void func(T1 a, T2 b) {
    cout << "func(T1 a,T2 b)" << endl;
}

template<typename T1, typename T2>
void func(T1 a, T2 b, int c) {
    cout << "func(T1 a, T2 b, int c)" << endl;
}


void func_template_precautions() {
    cout << endl << "========================func_template_precautions========================" << endl;

    CGirl g("西施");
    g.show(3);
    g.show("关羽");

    cout << endl;
    int bh = 3;
    string message = "我是一只啥啥鸟";
    show(bh, message);

    cout << endl;
    func(1);
    func(1, 2);
    func(1, 2, 3);

    cout << endl << "========================func_template_precautions========================" << endl;
}