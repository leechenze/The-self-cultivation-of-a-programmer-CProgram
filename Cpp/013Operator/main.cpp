//
// Created by Lee ChenZe on 1/21/24.
//



#include <stdio.h>
#include <iostream>

using namespace std;

void operator_basic();

void overloading_relational_operators();

void overloading_left_shift_operators();

void overloading_subscript_operators();

void overloading_assignment_operators();

void overloading_new_del_operators();

int simple_memory_pool();

void overloading_parenthesis_operators();

void overloading_unary_operators();


int main() {
    /** =========运算符重载基础(operator_basic)========= */
    operator_basic();

    /** =========重载关系运算符(overloading_relational_operators)========= */
    overloading_relational_operators();

    /** =========重载左移运算符(overloading_left_shift_operators)========= */
    overloading_left_shift_operators();

    /** =========重载下标运算符(overloading_subscript_operators)========= */
    overloading_subscript_operators();

    /** =========重载赋值运算符(overloading_assignment_operators)========= */
    overloading_assignment_operators();

    /** =========重载new和delete运算符(overloading_new_del_operators)========= */
    overloading_new_del_operators();

    /** =========实现简单的内存池(simple_memory_pool)========= */
    simple_memory_pool();

    /** =========重载括号运算符(overloading_parenthesis_operators)========= */
    overloading_parenthesis_operators();

    /** =========重载一元运算符(overloading_unary_operators)========= */
    overloading_unary_operators();


};

