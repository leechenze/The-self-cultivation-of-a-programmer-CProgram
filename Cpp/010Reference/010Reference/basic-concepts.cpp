//
//  basic-concepts.cpp
//  010Reference
//
//  Created by Lee ChenZe on 8/30/23.
//

#include <iostream>
using namespace std;

void basic_concepts() {
    cout << endl;
    
    // 基本语法
    int a = 3;
    int& ra = a;
    
    cout << "a的地址是: " << &a << ", a的值是: " << a << endl;
    cout << "ra的地址是: " << &ra << ", ra的值是: " << ra << endl;
    
    ra = 8;
    
    cout << "a的地址是: " << &a << ", a的值是: " << a << endl;
    cout << "ra的地址是: " << &ra << ", ra的值是: " << ra << endl;
    
    // 引用的本质
    // TODO
    
    
    
    
    
    
    cout << endl << endl << "==================basic-concepts==================" << endl;
}
