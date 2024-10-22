//
// Created by Lee ChenZe on 10/8/24.
//

#include <stdio.h>
#include <iostream>
#include <string>
#include <typeinfo>

using namespace std;


void auto_deduce_type();

void func_template_basic();

void func_template_precautions();

void func_template_specific();

void func_template_advanced();

int main() {
    /** =========自动推导类型auto(auto_deduce_type)========= */
    auto_deduce_type();
    /** =========函数模版的基本概念(func_template_basic)========= */
    func_template_basic();
    /** =========函数模版的注意事项(func_template_precautions)========= */
    func_template_precautions();
    /** =========函数模板的具体化(func_template_specific)========= */
    func_template_specific();
    /** =========函数模板高级(func_template_advanced)========= */
    func_template_advanced();
};

