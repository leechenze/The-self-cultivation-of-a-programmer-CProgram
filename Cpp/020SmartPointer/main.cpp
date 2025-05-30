//
// Created by Lee ChenZe on 5/30/25.
//
#include <stdio.h>
#include <iostream>
#include <string>
#include <typeinfo>

using namespace std;

void smart_pointer_unique_ptr();
void smart_pointer_shared_ptr();
void smart_pointer_remover();
void smart_pointer_weak_ptr();

int main() {
    /** =========智能指针unique_ptr(smart_pointer_unique_ptr)========= */
    smart_pointer_unique_ptr();
    /** =========智能指针unique_ptr(smart_pointer_shared_ptr)========= */
    smart_pointer_shared_ptr();
    /** =========智能指针的删除器(smart_pointer_remover)========= */
    smart_pointer_remover();
    /** =========智能指针的删除器(smart_pointer_weak_ptr)========= */
    smart_pointer_weak_ptr();


};

