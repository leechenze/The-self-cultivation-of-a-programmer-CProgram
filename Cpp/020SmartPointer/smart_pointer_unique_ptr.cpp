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

void func(unique_ptr<AA> &pp){
    cout << "name = " << pp->m_name << endl;
    // cout << "name = " << (*pp).m_name << endl;
}


// 函数func1()需要一个指针，但不对这个指针负责。
void func1(const AA* a) {
    cout << a->m_name << endl;
}

// 函数func2()需要一个指针，并且会对这个指针负责。
void func2(AA* a) {
    cout << a->m_name << endl;
    delete a;
}

// 函数func3()需要一个unique_ptr，不会对这个unique_ptr负责。
void func3(const unique_ptr<AA> &a) {
    cout << a->m_name << endl;
}

// 函数func4()需要一个unique_ptr，并且会对这个unique_ptr负责。
// 注意是传递值，而不是传引用。
void func4(unique_ptr<AA> a) {
    cout << a->m_name << endl;
}

void smart_pointer_unique_ptr() {
    cout << endl << "========================smart_pointer_unique_ptr========================" << endl;

    // // 使用已存在的地址初始化
    // AA *p = new AA("douglas");
    // unique_ptr<AA> pu1(p);
    // cout << "(*pu1).m_name = " << (*pu1).m_name << endl;
    // cout << "pu1->m_name = " << pu1->m_name << endl;
    // cout << "(*p).m_name = " << (*p).m_name << endl;
    // cout << "p->m_name = " << p->m_name << endl;

    // 分配内存并初始化
    // unique_ptr<AA> pu1(new AA("douglas"));
    // cout << "(*pu1).m_name = " << (*pu1).m_name << endl;
    // cout << "pu1->m_name = " << pu1->m_name << endl;

    // 不要用同一个裸指针初始化多个unique_ptr对象
    // AA *p = new AA("douglas");
    // unique_ptr<AA> pu1(p);
    //
    // cout << "裸指针的值是 = " << p << endl;
    // cout << "pu输出的值是 = " << pu1 << endl;
    // cout << "pu1.get()输出的值是 = " << pu1.get() << endl;
    // cout << "&pu1输出的值是 = " << &pu1 << endl;

    // AA *p = new AA("douglas");
    // unique_ptr<AA> pu1(p);
    // func(pu1);


    cout << endl << "========================更多技巧========================" << endl;

    // release 和 move
    unique_ptr<AA> pu(new AA("douglas"));
    cout << "开始调用函数" << endl;
    //func1(pu.get());        // 函数func1()需要一个指针，但不对这个指针负责。
    //func2(pu.release());  // 函数func2()需要一个指针，并且会对这个指针负责。
    //func3(pu);                // 函数func3()需要一个unique_ptr，不会对这个unique_ptr负责。
    func4(move(pu));     // 函数func4()需要一个unique_ptr，并且会对这个unique_ptr负责。
    cout << "完成调用函数" << endl;
    if (pu == nullptr) cout << "pu是空指针。\n";


    cout << endl << "========================smart_pointer_unique_ptr========================" << endl;
}
