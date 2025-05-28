//
// Created by Lee ChenZe on 5/27/25.
//
#include <iostream>;
#include <vector>

using namespace std;

void vector_container() {
    cout << endl << "========================vector_container========================" << endl;

    // // 创建一个空的vector容器
    // vector <int> v;
    // cout << "v.capacity() = " << v.capacity() << ", v.size() = " << v.size() << endl;
    //
    // // 创建vector容器, 元素个数为n，那么容量和实际大小都是n
    // vector <int> v1(8);
    // cout << "v1.capacity() = " << v1.capacity() << ", v1.size() = " << v1.size() << endl;
    //
    // // 使用统一初始化列表创建容器
    // // vector<int> v3({1,5,2,4,3});
    // vector<int> v3 = {1,5,2,4,3};
    // for(int ii = 0; ii < v3.size(); ii++){
    //     cout << v3[ii] << " ";
    // }

    cout << endl << "========================vector嵌套========================" << endl;

    vector<vector<int>> vv;

    vector <int> v({1,2,3,4,5});
    vv.push_back(v);
    v = {6,7,8,9,10};
    vv.push_back(v);
    v = {11,12,13,14,15};
    vv.push_back(v);

    for(int i = 0; i < vv.size(); i++) {
        for(int j = 0; j < vv[i].size(); j++) {
            cout << "vv[i][j] = " << vv[i][j] << " " << endl;
        }
        cout << endl;
    }

    cout << endl << "========================vector_container========================" << endl;
}