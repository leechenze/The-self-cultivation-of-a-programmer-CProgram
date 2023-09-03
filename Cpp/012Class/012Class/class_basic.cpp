//
//  class_basic.cpp
//  012Class
//
//  Created by Lee ChenZe on 9/3/23.
//

#include <iostream>
using namespace std;

// 定义超女结构体
struct st_girl{
    string name;
    int age;
    void setValue(string newName,int newAge);
    void show(){
        cout << "姓名: " << name << ", 年龄: " << age << endl;
    };
};
// 初始化超女结构体中定义的函数,当然也可以直接在结构体内初始化.(如:show函数)
void st_girl::setValue(string newName, int newAge){
    name = newName;
    age = newAge;
}

// 定义超女类
class cl_girl{
public:
    string name;
    int age;
    void setValue(string newName,int newAge);
    void show(){
        cout << "姓名: " << name << ", 年龄: " << age << endl;
    };
};
// 初始化超女类中定义的函数,当然也可以直接在类内初始化.(如:show函数)
void cl_girl::setValue(string newName, int newAge){
    name = newName;
    age = newAge;
}

void class_basic() {
    cout << endl;
    
    // 超女结构体
    st_girl stgirl;
    stgirl.setValue("harris", 20);
    stgirl.show();
    
    // 超女类
    cl_girl clgirl;
    clgirl.setValue("hillary", 25);
    clgirl.show();
    
    
    
    
    
    
    
    
    
    cout << endl << endl << "==================class_basic==================" << endl;
}
