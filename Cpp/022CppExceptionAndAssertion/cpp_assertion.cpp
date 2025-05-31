//
// Created by Lee ChenZe on 5/31/25.
//
#include <iostream>;
#include <fstream>;
#include <string>;

using namespace std;

// 把ptr2中的数据复制到ptr1中。
void copydata(void *ptr1, void *ptr2)
{
    // 断言ptr1和ptr2都不会为空。
    assert(ptr1 && ptr2);
    cout << "继续执行复制数据的代码......\n";
}

void cpp_assertion() {
    cout << endl << "========================cpp_assertion========================" << endl;

    int ii = 0, jj = 0;
    // 把ptr2中的数据复制到ptr1中。
    copydata(&ii, &jj);
    // copydata(nullptr, &jj);

    cout << endl << "========================cpp_assertion========================" << endl;
}
