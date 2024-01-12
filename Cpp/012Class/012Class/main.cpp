//
//  main.cpp
//  012Class
//
//  Created by Lee ChenZe on 9/3/23.
//


#include <stdio.h>
#include <iostream>

using namespace std;

void class_basic();

void constructor_func();

void copy_constructor();

void initializer_cuslist();

void const_decorate_func();

void this_point();

void static_member();

void simple_object_model();

void friend_basic();

int main() {
    /** =========类基础(class_basic)========= */
    class_basic();
    /** =========构造函数(constructor_func)========= */
    constructor_func();
    /** =========拷贝构造函数(copy_constructor)========= */
    copy_constructor();
    /** =========初始化列表(initializer_list)========= */
    initializer_cuslist();
    /** =========const修饰成员函数(const_decorate_func)========= */
    const_decorate_func();
    /** =========this指针(this_point)========= */
    this_point();
    /** =========静态成员(static_member)========= */
    static_member();
    /** =========简单对象模型(simple_object_model)========= */
    simple_object_model();
    /** =========友元(friend_basic)========= */
    friend_basic();

};

