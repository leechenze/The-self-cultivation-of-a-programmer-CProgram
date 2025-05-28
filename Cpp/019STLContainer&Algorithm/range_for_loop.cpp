//
// Created by Lee ChenZe on 5/28/25.
//
#include <iostream>;
#include <vector>
#include <list>

using namespace std;

class AA {
public:
    string m_name;

    AA() { cout << "默认构造函数AA()。\n"; }

    AA(const string &name) : m_name(name) { cout << "构造函数，name=" << m_name << "。\n"; }

    AA(const AA &a) : m_name(a.m_name) { cout << "拷贝构造函数，name=" << m_name << "。\n"; }

    AA &operator=(const AA &a) {
        m_name = a.m_name;
        cout << "赋值函数，name=" << m_name << "。\n";
        return *this;
    }

    ~AA() { cout << "析构函数，name=" << m_name << "。\n"; }
};



void range_for_loop() {
    cout << endl << "========================range_for_loop========================" << endl;

    // vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // // // 使用迭代器遍历容器v
    // // for (auto it = v.begin(); it != v.end(); it++) {
    // //     cout << *it << " " << endl;
    // // }
    // // 用范围for循环遍历容器v
    // for (int val : v) {
    //     cout << val << " " << endl;
    // }

    cout << endl << "========================元素为结构体或类的容器遍历========================" << endl;

    vector<AA> v;
	cout << "1111，v.capacity()=" << v.capacity() << "\n";
	v.emplace_back("西施");
	cout << "2222，v.capacity()=" << v.capacity() << "\n";
	v.emplace_back("冰冰");
	cout << "3333，v.capacity()=" << v.capacity() << "\n";
	v.emplace_back("幂幂");
	cout << "4444，v.capacity()=" << v.capacity() << "\n";

	for (const auto &a : v)
		cout << a.m_name << " ";
	cout << endl;

    cout << endl << "========================range_for_loop========================" << endl;
}
