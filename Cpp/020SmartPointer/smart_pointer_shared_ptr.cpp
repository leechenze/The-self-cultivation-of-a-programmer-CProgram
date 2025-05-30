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

void smart_pointer_shared_ptr() {
    cout << endl << "========================smart_pointer_shared_ptr========================" << endl;

    AA *p = new AA("douglas");
    shared_ptr<AA> sp0(p);
    cout << "sp0.use_count() = " << sp0.use_count() << endl;

    shared_ptr<AA> sp1(sp0);
    cout << "sp0.use_count() = " << sp0.use_count() << endl;
    cout << "sp1.use_count() = " << sp1.use_count() << endl;
    cout << "sp0->m_name = " << sp0->m_name << endl;
    cout << "sp1->m_name = " << sp1->m_name << endl;
    cout << "sp0.get() = " << sp0.get() << endl;
    cout << "sp1.get() = " << sp1.get() << endl;
    cout << "&*p = " << &*p << endl;

    cout << endl << "========================smart_pointer_shared_ptr========================" << endl;
}
