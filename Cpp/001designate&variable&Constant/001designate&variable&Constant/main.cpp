//
//  main.cpp
//  001designate&variable&Constant
//
//  Created by Lee ChenZe on 8/10/23.
//

#include <iostream>

// 声明宏常量
#define MONTHS 12
#define PI 3.1415926


// using namespace std;    指定缺省的命名空间
using namespace std;

int main() {
    
    cout << endl;
    /** =========输出数据========= */
    // std::cout               可以输出各种类型的数据
    std::cout << "hello world!\n";
    std::cout << 100;
    std::cout << 'L';
    // 输出一个换行
    std::cout << std::endl;
    
    // <<                      操作符可以拼接多个数据项
    std::cout << "hello world!\n";
    std::cout << 100 << 'L' << "lee";
    std::cout << 'X' << std::endl;
    std::cout << std::endl;
    
    // std::endl               也可以用于换行
    std::cout << std::endl;
    
    // using namespace std;    指定std命名空间
    cout << "hello world!\n";
    cout << 100 << endl;
    cout << 'M' << endl;
    cout << endl;
    
    
    
    
    cout << endl;
    /** =========变量========= */
    string name;
    int age;
    double weight;
    char sex;
    bool appearance;
    
    name = "hillary";
    age = 25;
    weight = 50.5;
    sex = 'X';
    appearance = true;
    
    cout << endl;
    cout << "姓名:" << name << ",年龄:" << age << ",体重:" << weight << ",性别:" << sex << ",颜值:" << appearance << endl;
    cout << endl;
    
    // 变量声明时赋初始值
    string name1 = "douglas";
    int age1 = 55;
    double weight1 = 60.5;
    char sex1 = 'Y';
    bool appearance1 = true;
    
    cout << endl;
    cout << "姓名:" << name1 << ",年龄:" << age1 << ",体重:" << weight1 << ",性别:" << sex1 << ",颜值:" << appearance1 << endl;
    cout << endl;
    
    
    
    
    
    cout << endl;
    /** =========常量========= */
    // 宏常量
    cout << "一年有:" << MONTHS << "个月" << endl;
    cout << "圆周率的值是:" << PI << endl;
    // 常量
    const int daysOfWeek = 7;
    cout << "一周有" << daysOfWeek << "天" << endl;
    cout << endl;
    
    
    
    
    
    cout << endl;
    /** =========输入数据========= */
    string name2;
    cout << "请输入姓名" << endl;
    cin >> name2;
    cout << "输入的姓名是" << name2 << endl;
    
    bool appearance2;
    cout << "请输入颜值(0不漂亮, 1漂亮)" << endl;
    cin >> appearance2;
    cout << "输入的颜值是" << appearance2 << endl;
    
    
    
    
    cout << endl;
}
