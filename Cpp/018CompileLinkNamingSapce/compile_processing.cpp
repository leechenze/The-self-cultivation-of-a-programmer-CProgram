//
// Created by Lee ChenZe on 5/23/25.
//

#include <iostream>;
#include "compile_processing_public.h";

using namespace std;

void compile_processing() {
    cout << endl << "========================compile_processing========================" << endl;

    show(3, "我是一只傻傻鸟");

    #ifdef _WIN32
        count << "这是windows系统. \n" << endl;
    #elif __linux__
        cout << "这是linux系统. \n" << endl;
    #elif __APPLE__
        cout << "这是mac系统. \n" << endl;
    #else
        cout << "这是未知系统. \n" << endl;
    #endif

    cout << endl << "========================compile_processing========================" << endl;
}