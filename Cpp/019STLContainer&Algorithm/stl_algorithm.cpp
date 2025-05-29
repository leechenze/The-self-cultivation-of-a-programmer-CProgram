//
// Created by Lee ChenZe on 5/29/25.
//
#include <iostream>;
#include <vector>;
#include <list>;
#include <unordered_map>;
#include <cstdio>;
#include <queue>;
#include <algorithm>;

using namespace std;



/*
 * 用于测试 foreach 的自定义函数
 */
template<typename T>
// 张三的个性化表白函数。
void zsshow(const T& no)
{
    cout << "亲爱的" << no << "号：我是一只傻傻鸟。\n";
}

template<typename T>
// 张三的个性化表白仿函数。
class czs
{
public:
    void operator()(const T& no) {
        cout << "亲爱的" << no << "号：我是一只傻傻鸟。\n";
    }
};

/*
 * 用于测试 findif 的自定义函数
 */
template<typename T>
bool zsshow1(const T& no,const T & in_no)    // 张三的个性化表白函数。
{
    if (no != in_no) return false;
    cout << "亲爱的" << no << "号：我是一只傻傻鸟。\n";
    return true;
}

template<typename T>
class czs1   // 张三的个性化表白仿函数。
{
public:
    bool operator()(const T& no, const T& in_no) {
        if (no != in_no) return false;
        cout << "亲爱的" << no << "号：我是一只傻傻鸟。\n";
        return true;
    }
};


/*
 * 用于测试 sort 的自定义函数
 */
template<typename T>
bool compasc(const T& left, const T& right)   {     // 普通函数，用于升序。
    return left < right;
}

template<typename T>
struct _less
{
    bool operator()(const T& left, const T& right) { // 仿函数，用于升序。
        return left < right;
    }
};

template<typename T>
bool compdesc(const T& left, const T& right) {     // 普通函数，用于降序。
    return left > right;
}

template<typename T>
class _greater
{
public:
    bool operator()(const T& left, const T& right) { // 仿函数，用于降序。
        return left > right;
    }
};

/**
 * 模拟实现foreach, findif, sort等函数
 */
template<typename T1, typename T2>
void foreach(const T1 first, const T1 last, T2 pfun)
{
    for (auto it = first; it != last; it++)
        // 以超女编号为实参调用类的operator()函数。
        pfun(*it);
};

template<typename T1, typename T2, typename T3>
T1 findif(const T1 first, const T1 last, T2 pfun,T3 in_no)
{
    for (auto it = first; it != last; it++)
        if (pfun(*it, in_no) ==true)  return it;        // 用迭代器调用函数对象。

    return last;
};

template<typename T, typename compare>
// 冒泡排序。
void bsort(const T first, const T last, compare comp)
{

    while (true) {
        // 本轮遍历已交换过元素的标识，true-交换过，false-未交换过。
        bool bswap = false;
        for (auto it = first;;) {
            // 左边的元素。
            auto left = it;
            it++;
            // 右边的元素。
            auto right = it;
            // 表示it1已经是最后一个元素了。
            if (right == last) break;

            // 如果左边的元素比右边大，交换它们的值。
            //if (*left > *right)
            // 如果左边的元素比右边小，交换它们的值。
            //if (*left < *right)
            // 排序规则：如果comp()返回true，left排在前面（升序），否则right排在前面（降序）。
            if (comp(*left, *right) == true) continue;

            // 交换两个元素的值。
            auto tmp = *right;
            *right = *left;
            *left = tmp;
            // 一轮遍历已交换过元素的标识。
            bswap = true;
        }

        // 如果在for循环中不曾交换过元素，说明全部的元素已有序。
        if (bswap == false) break;
    }
}

void stl_algorithm() {
    cout << endl << "========================stl_algorithm========================" << endl;


    cout << endl << "========================for_each========================" << endl;

    // 存放超女编号的容器。
    vector<int> bh = { 5,8,2,6,9,3,1,7 };
    // 存放超女编号的容器。
    // list<string> bh = { "05","08","02","06","09","03","01","07" };

    // 写一个函数，在函数中遍历容器，向超女表白，表白的方法可自定义。
    // 第三个参数是模板函数。
    foreach(bh.begin(), bh.end(), zsshow<int>);
    // 第三个参数是仿函数。
    // foreach(bh.begin(), bh.end(), czs<int>());

    cout << endl << "========================find_if========================" << endl;

    auto it1=findif(bh.begin(), bh.end(), zsshow1<int>,2);  // 第三个参数是模板函数。
    if (it1 == bh.end()) cout << "查找失败。\n";
    else cout << "查找成功：" << *it1 << endl;

    auto it2=findif(bh.begin(), bh.end(), czs1<int>(),33);       // 第三个参数是仿函数。
    if (it2 == bh.end()) cout << "查找失败。\n";
    else cout << "查找成功：" << *it2 << endl;


    cout << endl << "========================sort========================" << endl;

    vector<int> bh1 = { 5,8,2,6,9,33,1,7 };   // 存放超女编号的容器。
    //list<string> bh1 = { "05","08","02","06","09","03","01","07" };   // 存放超女编号的容器。

    //bsort(bh1.begin(), bh1.end(),compasc<int>);        // 普通函数（升序）。
    //bsort(bh1.begin(), bh1.end(), compdesc<int>);     // 普通函数（降序）。

    //bsort(bh1.begin(), bh1.end(),_less<int>());             // 仿函数（升序）。
    //bsort(bh1.begin(), bh1.end(), _greater<int>());      // 仿函数（降序）。

    //bsort(bh1.begin(), bh1.end(), less<int>());             // STL提供的仿函数（升序）。
    //bsort(bh1.begin(), bh1.end(), greater<int>());       // STL提供的仿函数（降序）。

    //sort(bh1.begin(), bh1.end(),_less<int>());             // 仿函数（升序）。
    sort(bh1.begin(), bh1.end(), _greater<int>());      // 仿函数（降序）。

    for (auto val : bh1)
        cout << val << " ";
    cout << endl;

    cout << endl << "========================stl_algorithm========================" << endl;
}
