//
//  enumeration.cpp
//  009StructureAndEnumeration
//
//  Created by Lee ChenZe on 8/30/23.
//

#include <stdio.h>
#include <iostream>

using namespace std;


void enumeration() {
    cout << endl;
    enum colors {red=0, yellow=1, blue=2, other=3};
    // 创建colors的枚举变量cc, 取值只能是colors中给定的值.
    colors cc = red;
    // 输入colors中的值.
    cout << "red=" << red << ",yellow=" << yellow << ",blue=" << blue << ",other=" << other << endl;
    // cc就是一个普通的整型变量,具备普通变量的全部特征,就是取值范围收到了限制,只能是colors中约定的四个值.
    switch (cc) {
        case red:
            cout << "红色\n" << endl;
            break;
        case yellow:
            cout << "黄色\n" << endl;
            break;
        case blue:
            cout << "蓝色\n" << endl;
            break;
        default:
            cout << "未知颜色\n" << endl;
    }
    // 将枚举强制转换为整数
    colors cc1 = colors(1);
    switch (cc1) {
        case red:
            cout << "红色\n" << endl;
            break;
        case yellow:
            cout << "黄色\n" << endl;
            break;
        case blue:
            cout << "蓝色\n" << endl;
            break;
        default:
            cout << "未知颜色\n" << endl;
    }
    
    
    
    
    
    
    cout << endl << endl << "==================enumeration==================" << endl;
};
