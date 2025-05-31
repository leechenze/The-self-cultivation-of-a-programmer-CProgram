//
// Created by Lee ChenZe on 5/31/25.
//
#include <iostream>;
#include <string>;
#include <vector>;

using namespace std;

// 表白函数
void zsshow(const int &no){
    cout << "亲爱的" << no << "号: 我是leonardo" << endl;
}
// 表白仿函数
class czs{
public:
    void operator()(const int &no){
        cout << "亲爱的" << no << "号: 我是leonardo" << endl;
    }
};

void lambda_func() {
    cout << endl << "========================lambda_func========================" << endl;

    // 存放超女编号的容器
    vector<int> v = {5, 8, 3};
    // 第三个参数是普通函数
    // for_each(v.begin(), v.end(), zsshow);
    // 第三个参数是仿函数
    // for_each(v.begin(), v.end(), czs());
    // 第三个参数是lambda表达式
    // for_each(v.begin(), v.end(), [](const int &no) {
    //     cout << "亲爱的" << no << "号: 我是leonardo" << endl;
    // });
    // 第三个参数是lambda表达式
    // auto anonymous_func = [](const int &no) {
    //     cout << "亲爱的" << no << "号: 我是leonardo" << endl;
    // };
    // for_each(v.begin(), v.end(), anonymous_func);


    cout << endl << "========================捕获列表========================" << endl;

    // int ii = 3;
    // double dd = 9.9;
    // auto anonymous_func = [ii,dd](const int &no) {
    //     cout << "ii = " << ii << endl;
    //     cout << "dd = " << dd << endl;
    //     cout << "亲爱的" << no << "号: 我是leonardo" << endl;
    // };
    // anonymous_func(8);

    cout << endl << "========================lambda_func========================" << endl;
}
