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

class AA;
class BB;

class AA{
public:
    string m_name;
    // shared_ptr<BB> m_p;
    weak_ptr<BB> m_p;
    AA() { cout << m_name << "调用默认构造函数" << endl; }
    AA(const string &name) : m_name(name) {
        cout << "调用构造函数AA, 参数 = " << m_name << endl;
    }
    ~AA() {
        cout << "调用析构函数~AA, 参数 = " << m_name << endl;
    }
};

class BB{
public:
    string m_name;
    // shared_ptr<AA> m_p;
    weak_ptr<AA> m_p;
    BB() { cout << m_name << "调用默认构造函数" << endl; }
    BB(const string &name) : m_name(name) {
        cout << "调用构造函数BB, 参数 = " << m_name << endl;
    }
    ~BB() {
        cout << "调用析构函数~BB, 参数 = " << m_name << endl;
    }
};


void smart_pointer_weak_ptr() {
    cout << endl << "========================smart_pointer_weak_ptr========================" << endl;

    // shared_ptr<AA> sp0 = make_shared<AA>("douglas");
    // shared_ptr<BB> sp1 = make_shared<BB>("beckham");
    //
    // sp0->m_p = sp1;
    // sp1->m_p = sp0;

    // weak_ptr没有重载 ->和 *操作符，不能直接访问资源。
    shared_ptr<AA> pa = make_shared<AA>("hamilton");
    {
        shared_ptr<BB> pb = make_shared<BB>("beckham");
        pa->m_p = pb;
        pb->m_p = pa;
        shared_ptr<BB> pp = pa->m_p.lock();            // 把weak_ptr提升为shared_ptr。
        if (pp == nullptr)
            cout << "语句块内部：pa->m_p已过期。\n";
        else
            cout << "语句块内部：pp->m_name=" << pp->m_name << endl;
    }

    shared_ptr<BB> pp = pa->m_p.lock();            // 把weak_ptr提升为shared_ptr。
    if (pp == nullptr)
        cout << "语句块外部：pa->m_p已过期。\n";
    else
        cout << "语句块外部：pp->m_name=" << pp->m_name << endl;

    cout << endl << "========================smart_pointer_weak_ptr========================" << endl;
}
