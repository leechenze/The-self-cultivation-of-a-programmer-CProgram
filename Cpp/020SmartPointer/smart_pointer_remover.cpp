//
// Created by Lee ChenZe on 5/30/25.
//
#include <iostream>;
#include <vector>;
#include <list>;
#include <unordered_map>;
#include <cstdio>;
#include <queue>;
#include <algorithm>;
#include <memory>;

using namespace std;

class AA{
public:
    string m_name;
    AA() { cout << m_name << "调用默认构造函数" << endl; }
    AA(const string &name) : m_name(name) {
        cout << "调用构造函数AA, 参数 = " << m_name << endl;
    }
    ~AA() {
        cout << "调用析构函数~AA, 参数 = " << m_name << endl;
    }
};

// 普通函数自定义删除器
void delFunc(AA *a) {
    cout << "普通函数自定义删除器(全局函数)" << endl;
    delete a;
}
// 仿函数自定义删除器
void delClassFunc(AA *a) {
    cout << "仿函数自定义删除器" << endl;
    delete a;
}



void smart_pointer_remover() {
    cout << endl << "========================smart_pointer_remover========================" << endl;

    // shared_ptr<AA> sp1(new AA("douglas"));

    // 普通函数自定义删除器
    // shared_ptr<AA> sp1(new AA("douglas"), delFunc);
    // shared_ptr<AA> sp1(new AA("douglas"), delClassFunc);

    // unique_ptr<AA, decltype(delFunc) *> up1(new AA("douglas"), delFunc);
    // unique_ptr<AA, void (*)(AA *)> up1(new AA("douglas"), delFunc);
    // unique_ptr<AA, decltype(delClassFunc) *> up1(new AA("douglas"), delClassFunc);
    // unique_ptr<AA, void (*)(AA *)> up1(new AA("douglas"), delClassFunc);


    cout << endl << "========================smart_pointer_remover========================" << endl;
}
