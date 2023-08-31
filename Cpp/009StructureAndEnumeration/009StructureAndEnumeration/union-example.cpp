//
//  union.cpp
//  009StructureAndEnumeration
//
//  Created by Lee ChenZe on 8/30/23.
//

#include <stdio.h>
#include <iostream>

using namespace std;

union udata{
    int     a;
    double  b;
    char    c[21];
};
// 创建嵌套于结构体中的匿名共同体
struct st_girl {
    int no;
    union {
        int     a;
        double  b;
        char    c[21];
    };
};


void union_example() {
    cout << endl;
    // 定义共同体变量
    udata data;
    cout << "sizeof(data) = " << sizeof(data) << endl;
    // 查看共同体中值的地址
    cout << "data.a的地址是: " << &data.a << endl;
    cout << "data.b的地址是: " << &data.b << endl;
    cout << "data.c的地址是: " << &data.c << endl;
    // 访问结构体中的匿名共同体(匿名共同体的成员可以当作结构体的成员直接访问)
    st_girl sg;
    cout << "sg.a的地址是: " << &sg.a << endl;
    cout << "sg.b的地址是: " << &sg.b << endl;
    cout << "sg.c的地址是: " << &sg.c << endl;
    
    
    cout << endl << endl << "==================union_example==================" << endl;
};
