//
// Created by Lee ChenZe on 5/28/25.
//
#include <iostream>;
#include <vector>;
#include <list>;
#include <map>;

using namespace std;

// 超女类。
class CGirl
{
public:
    // 超女姓名。
    string m_name;
    // 超女年龄。
    int      m_age;

    /*CGirl() : m_age(0) {
        cout << "默认构造函数。\n";
    }*/
    CGirl(const string name, const int age) : m_name(name), m_age(age) {
        cout << "两个参数的构造函数。\n";
    }
    CGirl(const CGirl & g) : m_name(g.m_name), m_age(g.m_age) {
        cout << "拷贝构造函数。\n";
    }
};

// 封装打印方法
void printMap(const map<int, string> &m, const string &title = ""){
    if (!title.empty()) {
        cout << title << endl;
    }
    for(const auto &val : m){
        cout << "val.first = " << val.first << ", val.second = " << val.second << endl;
    }
    cout << endl;
}

void map_container() {
    cout << endl << "========================map_container========================" << endl;

    // 创建一个空的map容器;
    map<int,string> m1;
    // 使用统一初始化列表
    map<int, string> m2 ({{8, "douglas"}, {3, "nixon"}, {1, "hillary"}, {7, "clinton"}, {5, "blinken"}});
    printMap(m2);

    // 拷贝构造函数
    map<int, string> m3 = m2;
    printMap(m3);

    // 用迭代器创建map容器
    auto first = m3.begin(); first++;
    auto last = m3.end(); last--;
    map<int, string> m4(first, last);
    printMap(m4);


    cout << endl << "========================用给定的key访问val========================" << endl;

    cout << "m2[8] = " << m2[8] << endl;
    cout << "m2[8] = " << m2[9] << endl;
    printMap(m2);

    cout << endl << "========================插入元素========================" << endl;

    m2.insert({10, "hamilton"});
    m2.insert({{11, "trump"}, pair<int, string>(12, "obama"), make_pair<int, string>(13, "bush")});
    printMap(m2);

    cout << endl << "========================pair<iterator,bool> insert(const pair<K,V> &value)========================" << endl;

    pair<map<int, string>::iterator, bool> ret = m2.insert(pair<int, string>(14, "lincoln"));
    if(ret.second == true) {
        cout << "插入成功" << ret.first->first << ", " << ret.first->second << endl;
    }else{
        cout << "插入失败" << endl;
    }
    printMap(m2);

    auto ret1 = m2.emplace(15, "jackchen");
    if(ret1.second == true) {
        cout << "插入成功" << ret1.first->first << ", " << ret1.first->second << endl;
    }else{
        cout << "插入失败" << endl;
    }
    printMap(m2);


    cout << endl << "========================分段构造========================" << endl;

    map<int, CGirl> m5;
    // 一次构造函数，两次拷贝构造函数。
    m5.insert(pair<int, CGirl>(8, CGirl("冰冰", 18)));
    // 一次构造函数，两次拷贝构造函数。
    m5.insert(make_pair<int, CGirl>(8, CGirl("冰冰", 18)));
    // 一次构造函数，两次拷贝构造函数。
    m5.emplace(pair<int, CGirl>(8, CGirl("冰冰", 18)));
    // 一次构造函数，两次拷贝构造函数。
    m5.emplace(make_pair<int, CGirl>(8, CGirl("冰冰", 18)));
    // 一次构造函数，一次拷贝构造函数。
    m5.emplace(8, CGirl("冰冰", 18));
    // 错误, 如果遇见这种情况就需要使用cpp的分段构造，请看下面方案
    // m5.emplace(8, "冰冰", 18);
    // 一次构造函数，分段构造函数
    m5.emplace(piecewise_construct, forward_as_tuple(8), forward_as_tuple("冰冰", 18));

    cout << endl << "========================iterator emplace_hint(const_iterator pos, ...)========================" << endl;
    // 功能与 pair<iterator,bool> insert(const pair<K,V> &value) 的函数相同，
    // 第一个参数提示插入位置，该参数只有参考意义，如果提示的位置是正确的，
    // 对性能有提升，如果提示的位置不正确，性能反而略有下降，但是，插入是否成功与该参数元关。
    // 该参数常用end()和begin()。成功返回新插入元素的迭代器；如果元素已经存在，则插入失败，返回现有元素的迭代器。
    m2.emplace_hint(m2.begin(), piecewise_construct, forward_as_tuple(19), forward_as_tuple("ang"));
    printMap(m2);

    cout << endl << "========================map_container========================" << endl;
}