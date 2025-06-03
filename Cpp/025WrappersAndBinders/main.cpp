//
// Created by Lee ChenZe on 6/3/25.
//
#include <stdio.h>
#include <iostream>
#include <string>
#include <typeinfo>

using namespace std;

void callable_objects();
void wrapper_function();
void binder_bind();
void implementing_variadic_functions();
void callback_function_implementation();


int main() {
    /** =========可调用对象(callable_objects)========= */
    callable_objects();
    /** =========包装器function(wrapper_function)========= */
    wrapper_function();
    /** =========适配器bind(binder_bind)========= */
    binder_bind();
    /** =========可变函数和参数的实现(implementing_variadic_functions)========= */
    implementing_variadic_functions();
    /** =========回调函数的实现(callback_function_implementation)========= */
    callback_function_implementation();

};

