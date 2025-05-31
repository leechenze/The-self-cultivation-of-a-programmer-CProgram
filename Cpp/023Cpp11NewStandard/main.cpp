//
// Created by Lee ChenZe on 5/31/25.
//
#include <stdio.h>
#include <iostream>
#include <string>
#include <typeinfo>

using namespace std;

void cpp_new_standard();
void delegate_construction_and_inheritance_construction();
void lambda_func();
void r_value_references();
void move_semantics();

int main() {
    /** =========cpp的新标准(cpp_new_standard)========= */
    cpp_new_standard();
    /** =========委托构造和继承构造(delegate_construction_and_inheritance_construction)========= */
    delegate_construction_and_inheritance_construction();
    /** =========Lambda函数(lambda_func)========= */
    lambda_func();
    /** =========右值引用(r_value_references)========= */
    r_value_references();
    /** =========移动语义(move_semantics)========= */
    move_semantics();


};

