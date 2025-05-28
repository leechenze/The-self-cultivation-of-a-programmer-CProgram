//
// Created by Lee ChenZe on 5/28/25.
//
#include <iostream>;
#include <vector>;
#include <list>;

using namespace std;

void list_container() {
    cout << endl << "========================list_container========================" << endl;

    // 创建一个空的list容器
    list<int> l1;
    cout << "l1.size()" << l1.size() << " " << endl;

    // cpp11标准初始化列表的三种写法
    list<int> l2 ({1,2,3,4,5});
    // list<int> l2 = {1,2,3,4,5};
    // list<int> l2 {1,2,3,4,5};
    for (int val : l2) {
        cout << val << " " << endl;
    }

    // 拷贝构造函数
    list<int> l3(l2);

    // 迭代器创建list容器
    list<int> l4(l3.begin(), l3.end());
    for (int val : l4) {
        cout << val << " " << endl;
    }
    cout << endl;

    cout << "用数组指针作为迭代器创建list容器" << endl;

    // 用数组指针作为迭代器创建list容器
    int a1[] = {1,2,3,4,5,6};
    list<int> l5 (a1, a1 + sizeof(a1) / sizeof(a1[0]));
    for (int val : l5) {
        cout << val << " " << endl;
    }
    cout << endl;

    cout << endl << "========================排序操作========================" << endl;

    list<int> l6 = {8,2,6,4,5};
    for(auto &val: l6) {
        cout << val << " " << endl;
    }
    cout << endl;

    // 反转列表
    l6.reverse();

    for(auto &val: l6) {
        cout << val << " " << endl;
    }
    cout << endl;

    // 链表排序
    l6.sort();
    for(auto &val: l6) {
        cout << val << " " << endl;
    }
    cout << endl;

    cout << endl << "========================合并操作========================" << endl;

    list<int> l7 ({3,7,9,10,1});
    l7.sort();
    l6.merge(l7);
    for(auto &val: l6) {
        cout << val << " " << endl;
    }
    cout << endl;


    cout << endl << "========================list_container========================" << endl;
}
