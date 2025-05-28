//
// Created by Lee ChenZe on 5/27/25.
//
#include <iostream>;
#include <vector>
#include <list>

using namespace std;

// 单链表的结点。
struct Node
{
    int item;
    Node *next;
};

// 在整型数组arr中查找值为val的元素。
int* find_(int* arr, int n, const int& val)
{
    // 遍历数组。
    for (int ii = 0; ii < n; ii++)
        // 如果找到了，返回数组中元素的地址。
        if (arr[ii] == val) return &arr[ii];
    return nullptr;
}

// 在整型数组的区间中查找值为val的元素。
int* find_(int* begin, int* end, const int& val)
{
    // 遍历查找区间。
    for (int* iter = begin; iter != end; iter++)
        // 如果找到了元素，返回区间中的位置。
        if (*iter == val) return iter;
    return nullptr;
}

// 在单链表中查找值为val的元素。
Node* find_(Node* begin, Node* end, const Node& val)
{
    // 遍历链表。
    for (Node * iter = begin; iter != end; iter = iter->next)
        // 如果找到了，返回链表中结点的地址。
        if (iter->item == val.item) return iter;
    return nullptr;
}

// 查找元素的算法。
template<typename T1, typename T2>
// begin-查找区间开始的位置；end-查找区间结束的位置；val-待查找的值。
T1 find_(T1 begin, T1 end, const T2 &val) {
    // 遍历查找区间。
    for (T1 iter = begin; iter != end; iter++)
        // 如果找到了元素，返回区间中的位置。
        if (*iter == val) return iter;
    return end;
}


void cus_iterator() {
    cout << endl << "========================cus_iterator========================" << endl;

    // // 在vector容器中查找元素。
    // vector<int> vv = { 1,2,3,4,5 };      // 初始化vector容器。
    // vector<int>::iterator it2 = find_(vv.begin(), vv.end(), 3);
    // if (it2 != vv.end()) cout << "查找成功。\n";
    // else cout << "查找失败。\n";
    //
    // // 在list容器中查找元素。
    // list<int> ll = {1,2,3,4,5};               // 初始化vector容器。
    // list<int>::iterator it3 = find_(ll.begin(), ll.end(), 3);
    // if (it3 != ll.end()) cout << "查找成功。\n";
    // else cout << "查找失败。\n";

    cout << endl << "========================正向迭代器========================" << endl;

    // // 初始化Vector容器
    // vector<int> v = {1, 2, 3, 4, 5};
    // // 定义容器迭代器开始
    // vector<int>::iterator it = v.begin();
    //
    // // 修改容器中的第0个元素
    // *it = 8;
    // // 迭代器后移一个元素
    // it++;
    // // 修改容器中第0个元素
    // *it = 7;
    //
    // for(vector<int>::const_iterator it1 = v.begin(); it1 != v.end(); it1++){
    //     cout << *it1 << " " << endl;
    // }
    // // // 使用auto类型声明迭代器也可以
    // // for(auto it1 = v.begin(); it1 != v.end(); it1++){
    // //     cout << *it1 << " " << endl;
    // // }

    cout << endl << "========================vector使用迭代器的构造函数========================" << endl;

    // 初始化vector容器
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> v1(v.cbegin() + 2, v.cend() - 3);
    for(auto it = v1.cbegin(); it != v1.cend(); it++) {
        cout << *it << " " << endl;
    }
    cout << endl;
    // 改为反向迭代器
    for(auto it = v1.crbegin(); it != v1.crend(); it++) {
        cout << *it << " " << endl;
    }

    cout << endl << "========================cus_iterator========================" << endl;
}
