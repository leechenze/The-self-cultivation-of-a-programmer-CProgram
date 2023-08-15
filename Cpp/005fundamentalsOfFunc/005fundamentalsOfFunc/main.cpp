//
//  main.cpp
//  005fundamentalsOfFunc
//
//  Created by Lee ChenZe on 8/15/23.
//

#include "funcs.hpp"
#include "tools.hpp"

int main(int argc, const char * argv[]) {
    /** =========函数调用========= */
    cout << "man(5,8) = " << maxNum(5,8) << endl;
    cout << endl;


    /** =========变量的作用域========= */
    func1();
    func1("func1参数变量message");
    cout << endl;
    // 静态变量
    func2();
    func2();
    func2();
    cout << endl;
    // 代码块内使用重名全局变量;
    func3();
    cout << endl;


    /** =========函数参数传递========= */
    func4(8, "我是你的上帝");


    /** =========函数分文件编写========= */




    cout<<endl;
}
