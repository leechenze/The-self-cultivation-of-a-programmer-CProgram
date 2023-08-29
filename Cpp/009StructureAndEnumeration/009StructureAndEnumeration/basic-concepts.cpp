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
struct st_t {
    int a;
    int *p;
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
    // 结构体中的指针
    st_t stt;
    stt.a = 3;
    memset(&stt, 0, sizeof(st_t));
    stt.p = new int[100];
    cout << "sizeof(stt) = " << sizeof(stt) << endl;
    cout << "调用前: stt.a = " << stt.a << ", stt.p = " << stt.p << endl;
    // 不要整个结构体清空.
    // memset(&stt, 0, sizeof(st_t));
    stt.a=0;
    // 清空需要对每一个结构体成员进行清空,最好不要对整个结构体进行清空.
    // 因为难免结构体中会有指针动态内存分配(new xxx),而导致的空地址.
    memset(stt.p,0,100 * sizeof(int));
    cout << "调用后: stt.a = " << stt.a << ", stt.p = " << stt.p << endl;
    
    delete []stt.p;
    
    
    
    
    cout << endl << endl << "==================basic-concepts==================" << endl;
}
