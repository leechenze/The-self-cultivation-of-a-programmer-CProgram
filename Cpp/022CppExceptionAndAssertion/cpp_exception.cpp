//
// Created by Lee ChenZe on 5/31/25.
//
#include <iostream>;
#include <fstream>;
#include <string>;

using namespace std;

void cpp_exception() {
    cout << endl << "========================cpp_exception========================" << endl;

    try{
        int ii = 0;
        cout << "Who are you？（1.leonardo; 2.douglas）";
        cin >> ii;
        if (ii== 1) {
            throw "No, I'm not leonardo";
        }
        cout << "I'm douglas" << endl;
    }
    catch (const std::exception& e) {
        cout << "标准异常: " << e.what() << endl;
    }
    // ...表示捕获所有未被具体匹配的异常
    catch (...) {
        cout << "捕获到未知类型的异常" << endl;
    }

    cout << "程序继续运行" << endl;

    cout << endl << "========================cpp_exception========================" << endl;
}
