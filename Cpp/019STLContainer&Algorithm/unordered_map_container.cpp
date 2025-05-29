//
// Created by Lee ChenZe on 5/28/25.
//
#include <iostream>;
#include <vector>;
#include <list>;
#include <unordered_map>;
#include <cstdio>;


using namespace std;

template<class K, class V>
using umap = unordered_map<K, V>;

// 封装打印方法
void printMap(const umap<int, string> &m, const string &title = ""){
    if (!title.empty()) {
        cout << title << endl;
    }
    for(const auto &val : m){
        cout << "val.first = " << val.first << ", val.second = " << val.second << endl;
    }
    cout << endl;
}


void unordered_map_container() {
    cout << endl << "========================unordered_map_container========================" << endl;

    // 创建一个空的umap容器;
    umap<int,string> m1;
    // 使用统一初始化列表
    umap<int, string> m2 ({{8, "douglas"}, {3, "nixon"}, {1, "hillary"}, {7, "clinton"}, {5, "blinken"}});
    printMap(m2);

    // 拷贝构造函数
    umap<int, string> m3 = m2;
    printMap(m3);

    // 用迭代器创建map容器
    auto first = m3.begin(); first++;
    auto last = m3.end();
    umap<int, string> m4(first, last);
    printMap(m4);


    cout << endl << "========================umap中的桶的自动扩展========================" << endl;

    umap<int, string> m5;
    cout << "m5.bucket_count() = " << m5.bucket_count() << endl;
    size_t itmp = m5.bucket_count();
    for(int i = 0; i < 20000; i++) {
        char name[50];
        snprintf(name, sizeof(name), "douglas%d", i);
        m5.emplace(i, name);
        if(itmp != m5.bucket_count()) {
            // 如果桶自动扩展显示日志
            cout << m5.bucket_count() << endl;
            itmp = m5.bucket_count();
        }
    }

    cout << endl << "========================unordered_map_container========================" << endl;
}
