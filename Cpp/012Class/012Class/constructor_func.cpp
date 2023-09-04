//
//  constructor_func.cpp
//  012Class
//
//  Created by Lee ChenZe on 9/4/23.
//

#include <iostream>
using namespace std;

class Person1{
public:
    string m_name;
    int m_age;
    char m_memo[301];
    // 定义和初始化构造函数
    Person1() {
        m_name.clear();
        m_age = 0;
        memset(m_memo, 0, sizeof(m_memo));
    }
    ~Person1() {
        cout << "调用了Person1析构函数" << endl;
    }
    void show() {
        cout << "姓名: " << m_name << ", 年龄: " << m_age << ", 备注: " << m_memo << endl;
    }
};

void constructor_func() {
    cout << endl;
    
    Person1 person1;
    person1.show();
    // 手动调用析构函数
    person1.~Person1();
    
    
    
    cout << endl << endl << "==================constructor_func==================" << endl;
}
