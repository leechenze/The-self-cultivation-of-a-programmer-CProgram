//
// Created by Lee ChenZe on 5/26/25.
//

#include <stdio.h>
#include <iostream>
#include <string>
#include <typeinfo>

using namespace std;

void string_container();
void vector_container();
void cus_iterator();
void range_for_loop();
void list_container();
void key_value_pair();
void map_container();
void unordered_map_container();
void queue_container();
void stl_algorithm();


int main() {
    /** =========string容器(string_container)========= */
    string_container();
    /** =========vector容器(vector_container)========= */
    vector_container();
    /** =========迭代器(cus_iterator)========= */
    cus_iterator();
    /** =========范围for循环(range_for_loop)========= */
    range_for_loop();
    /** =========list容器(list_container)========= */
    list_container();
    /** =========pair键值对(key_value_pair)========= */
    key_value_pair();
    /** =========map容器(map_container)========= */
    map_container();
    /** =========unordered_map容器(unordered_map_container)========= */
    unordered_map_container();
    /** =========queue容器(queue_container)========= */
    queue_container();
    /** =========STL算法(stl_algorithm)========= */
    stl_algorithm();



};

