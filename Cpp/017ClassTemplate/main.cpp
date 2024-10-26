//
// Created by Lee ChenZe on 10/22/24.
//

#include <stdio.h>
#include <iostream>
#include <string>
#include <typeinfo>

using namespace std;


void class_template_basic();

void template_class_stack();

void template_class_array();

void joint_and_recursive_use_of_templates();

void template_class_specific();

void template_class_inherit();

void template_class_func();

void template_class_friendship();

void member_template_class();

void params_template_class();

int main() {
    /** =========类模版的基本概念(class_template_basic)========= */
    class_template_basic();
    /** =========模版类的示例-栈(template_class_stack)========= */
    template_class_stack();
    /** =========模版类的示例-数组(template_class_array)========= */
    template_class_array();
    /** =========嵌套和递归使用模版类(joint_and_recursive_use_of_templates)========= */
    joint_and_recursive_use_of_templates();
    /** =========模版类的具体化(template_class_specific)========= */
    template_class_specific();
    /** =========模板类与继承(template_class_inherit)========= */
    template_class_inherit();
    /** =========模板类与函数(template_class_func)========= */
    template_class_func();
    /** =========模板类与友元(template_class_friendship)========= */
    template_class_friendship();
    /** =========成员模板类(member_template_class)========= */
    member_template_class();
    /** =========将模板类用作参数(params_template_class)========= */
    params_template_class();


};

