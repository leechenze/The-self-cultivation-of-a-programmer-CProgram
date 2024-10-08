//
// Created by Lee ChenZe on 10/5/24.
//

#include <stdio.h>
#include <iostream>

using namespace std;

void class_inherit_basic();

void inherit_mode();

void inherit_obj_model();

void structure_basic_class();

void name_shield_class_scope();

void special_inherit();

void more_and_virtual_inherit();

int main() {
    /** =========继承的基本概念(class_inherit_basic)========= */
    class_inherit_basic();
    /** =========继承方式(inherit_mode)========= */
    inherit_mode();
    /** =========继承的对象模型(inherit_obj_model)========= */
    inherit_obj_model();
    /** =========构造基类(structure_basic_class)========= */
    structure_basic_class();
    /** =========名字遮蔽与类作用域(name_shield_class_scope)========= */
    name_shield_class_scope();
    /** =========继承的特殊关系(special_inherit)========= */
    special_inherit();
    /** =========多继承与虚继承(more_and_virtual_inherit)========= */
    more_and_virtual_inherit();


};

