//
//  structure-array.cpp
//  009StructureAndEnumeration
//
//  Created by Lee ChenZe on 8/28/23.
//


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
struct super_girl1{
    string name;
    int score[3];
    int age;
    double weight;
    char sex;
    bool appearance;
};
struct super_girl2{
    string name;
    int score[2][3] = {{10,11,12},{20,21,22}};
    int age;
    double weight;
    char sex;
    bool appearance;
};
struct sg_pet {
    string name;
    string type;
};
struct super_girl3{
    string name;
    int age;
    double weight;
    char sex;
    bool appearance;
    sg_pet pet;
};

void func1(const super_girl* sg);
void func2(super_girl2* sg2);

void structure_array() {
    cout << endl;
    super_girl sg[3];
    memset(sg, 0, sizeof(sg));
    
    // strcpy(sg[0].name, "harris");
    sg[0].name = "harris";
    sg[0].age = 10;
    sg[0].weight = 48;
    sg[0].sex = 'X';
    sg[0].appearance = true;
    sg[1] = {"alice paul", 30,55,'X',true};
    // 前面都是用数组表示法赋值,这个用指针表示法对最后一位赋值.
    *(sg + 2) = {"Elizabeth", 50,45,'X',true};
    for(int i = 0; i < 3; i++) {
        func1(&sg[i]);
    }
    
    // 在结构体中嵌入数组
    super_girl1 sg1;
    for(int i = 0; i < 3; i++) {
        sg1.score[i] = 100 + i;
    }
    for(int i = 0; i < 3; i++) {
        cout << "sg1[" << i << "]" << sg1.score[i] << endl;
    }
    // 多维数组作为结构体成员,将结构体地址传递给函数对多维数组进行操作
    super_girl2 sg2;
    func2(&sg2);
    
    // 结构体中嵌套结构体
    super_girl3 sg3 = {"hillary", 36,45,'X',true,{"Ethan","dog"}};
    sg3.pet = {"Robin","cat"};
    cout
    << "姓名 = " << sg3.name << endl
    << "年龄 = " << sg3.age << endl
    << "体重 = " << sg3.weight << endl
    << "性别 = " << sg3.sex << endl
    << "颜值 = " << sg3.appearance << endl
    << "宠物名称 = " << sg3.pet.name << endl
    << "宠物是一只 = " << (sg3.pet.type == "cat" ? "喵咪" : "秀狗") << endl
    << endl;
    
    
    
    cout << endl << endl << "==================structure-array==================" << endl;
};

void func1(const super_girl* sg){
    // 如果不希望修改结构体中某个变量的值,就用const对参数进行约定.
    // psg -> name = "obama";
    cout
    << "姓名 = " << (*sg).name << endl
    << "年龄 = " << (*sg).age << endl
    << "体重 = " << (*sg).weight << endl
    << "性别 = " << (*sg).sex << endl
    << "颜值 = " << (*sg).appearance << endl
    << endl;
}

void func2(super_girl2* sg2){
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 3; j++) {
            cout << "sg2[" << i << "]" << "[" << j << "] = " << (*sg2).score[i][j] << endl;
        }
    }
}
