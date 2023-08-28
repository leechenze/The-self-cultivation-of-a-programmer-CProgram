//
//  main.cpp
//  009StructureAndEnumeration
//
//  Created by Lee ChenZe on 8/27/23.
//

#include <iostream>
using namespace std;
// 修改内存对齐的规则
#pragma pack(1)

struct super_girl{
    string name;
    int age;
    double weight;
    char sex;
    bool appearance;
};
struct super_girl1{
    string name;
    int age;
    double weight;
    char sex;
    bool appearance;
} superGirl1 = {"harris",18,51,'X',false};
struct super_girl2{
    string name = "hillary";
    int age = 25;
    double weight = 48;
    char sex = 'X';
    bool appearance = true;
};

void basic_concepts() {
    cout << endl;
    // c语言生命结构体变量之前必须加上struct关键字,cpp可以不加.
    super_girl superGirl = {"hillary",25,48,'Y',true};
    cout
    << "姓名" << superGirl.name << endl
    << "年龄" << superGirl.age << endl
    << "体重" << superGirl.weight << endl
    << "性别" << superGirl.sex << endl
    << "颜值" << superGirl.appearance << endl
    << endl;
    cout
    << "姓名" << superGirl1.name << endl
    << "年龄" << superGirl1.age << endl
    << "体重" << superGirl1.weight << endl
    << "性别" << superGirl1.sex << endl
    << "颜值" << superGirl1.appearance << endl
    << endl;
    // 占用的内存大小:修改内存对齐规则为1后,可以得到每个成员占用内存正确的和.
    cout << "sizeof(superGirl) = " << sizeof(superGirl) << endl;
    // 清空结构体:一下两个函数用哪一个都可以
    memset(&superGirl1,0,sizeof(superGirl1));
    bzero(&superGirl1,sizeof(superGirl1));
    cout
    << "姓名" << superGirl1.name << endl
    << "年龄" << superGirl1.age << endl
    << "体重" << superGirl1.weight << endl
    << "性别" << superGirl1.sex << endl
    << "颜值" << superGirl1.appearance << endl
    << endl;
    // 复制结构体
    super_girl superGirlCpy;
    memcpy(&superGirlCpy, &superGirl,sizeof(super_girl));
    cout
    << "姓名" << superGirl.name << endl
    << "年龄" << superGirl.age << endl
    << "体重" << superGirl.weight << endl
    << "性别" << superGirl.sex << endl
    << "颜值" << superGirl.appearance << endl
    << endl;
    
    
    
    
    
    cout << endl << endl << "==================basic-concepts==================" << endl;
}
