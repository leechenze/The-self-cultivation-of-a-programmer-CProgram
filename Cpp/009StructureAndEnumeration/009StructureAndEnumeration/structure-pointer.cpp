//
//  structure-pointer.cpp
//  009StructureAndEnumeration
//
//  Created by Lee ChenZe on 8/28/23.
//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>

using namespace std;

struct super_girl{
    string name;
    int age;
    double weight;
    char sex;
    bool appearance;
};

void func(const super_girl *psg);

void structure_pointer() {
    cout << endl;
    super_girl superGirl = {"hillary",25,48,'Y',true};
    cout
    << "姓名" << superGirl.name << endl
    << "年龄" << superGirl.age << endl
    << "体重" << superGirl.weight << endl
    << "性别" << superGirl.sex << endl
    << "颜值" << superGirl.appearance << endl
    << endl;
    super_girl *psg = &superGirl;
    // 通过结构体指针访问结构体成员变量方法一
    cout
    << "姓名" << (*psg).name << endl
    << "年龄" << (*psg).age << endl
    << "体重" << (*psg).weight << endl
    << "性别" << (*psg).sex << endl
    << "颜值" << (*psg).appearance << endl
    << endl;
    // 通过结构体指针访问结构体成员变量方法二
    cout
    << "姓名" << psg -> name << endl
    << "年龄" << psg -> age << endl
    << "体重" << psg -> weight << endl
    << "性别" << psg -> sex << endl
    << "颜值" << psg -> appearance << endl
    << endl;
    // 用于函数的参数
    func(&superGirl);
    // 用于动态分配内存
    // 方式一:可以什么都不填({}),也可以填一个0({0}),结果是一样的.
    // super_girl *psg1 = new super_girl({});
    super_girl *psg1 = new super_girl({"hillary",25,48,'Y',true});
    // 方式二
    // super_girl *psg1 = new super_girl;
    // memset(psg1, 0, sizeof(super_girl));
    cout
    << "姓名: " << psg1 -> name << endl
    << "年龄: " << psg1 -> age << endl
    << "体重: " << psg1 -> weight << endl
    << "性别: " << psg1 -> sex << endl
    << "颜值: " << psg1 -> appearance << endl
    << endl;
    
    
    
    cout << endl << endl << "==================structure-pointer==================" << endl;
};

void func(const super_girl* psg){
    // 如果不希望修改结构体中某个变量的值,就用const对参数进行约定.
    // psg -> name = "obama";
    cout
    << "姓名 = " << psg -> name << endl
    << "年龄 = " << psg -> age << endl
    << "体重 = " << psg -> weight << endl
    << "性别 = " << psg -> sex << endl
    << "颜值 = " << psg -> appearance << endl
    << endl;
}
