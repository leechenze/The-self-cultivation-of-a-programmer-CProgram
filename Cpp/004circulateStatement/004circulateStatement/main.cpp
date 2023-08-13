//
//  main.cpp
//  004circulateStatement
//
//  Created by Lee ChenZe on 8/13/23.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    int no = 1;
    /** =========while=========*/
    while(no <= 10) {
        cout << "总统编号是: "<< no << endl;
        no++;
    }
    cout << endl;
    
    
    
    
    /** =========循环的跳转=========*/
    bool once = true;
    int level;
    bool exist;
    while(true) {
        // 第一次执行时不询问是否继续下一个
        if(once == false){
            cout << "是否继续下一个: " << endl;
            cin >> exist;
            if(!exist) break;
        }
        cout << "请输入级别: " << endl;
        cin >> level;
        if (level == 1) {
            cout << "优秀" << endl;
        } else if (level == 2) {
            cout << "合格" << endl;
        } else if (level == 3) {
            cout << "差劲" << endl;
        }
        once = false;
    };
    
    
    
    
    /** =========for=========*/
    for(int i = 0; i < 10; i++) {
        cout << "当前的值是: " << i << endl;
    }
    cout << endl;
    
    
    
    
    
    /** =========嵌套循环=========*/
    // 99乘法表
    for(int n = 1; n <= 9; n++) {
        for(int m = 1; m <= n; m++) {
            cout << n << "*" << m << "=" << n*m << " ";
        };
        cout << endl;
    };
    cout << endl;
    
    
    
    
    /** =========do while=========*/
    int a = 10;
    do{
        cout << a++ << endl;
    }while(a < 20);
    cout << endl;
    
    
    
    
    /** =========goto=========*/
    // goto 演示:
    cout << "第1个程序员的编号" << endl;
    goto bbb;
    cout << "第2个程序员的编号" << endl;
    cout << "第3个程序员的编号" << endl;
    cout << "第4个程序员的编号" << endl;
    bbb: cout << "第5个程序员的编号" << endl;
    
    cout << endl;
    
    // goto 循环:
    cout << "第1个程序员的编号" << endl;
    int b = 1;
    ccc:
    cout << "第2个程序员的编号" << endl;
    cout << "第3个程序员的编号" << endl;
    cout << "第4个程序员的编号" << endl;
    b++;
    if(b <= 3) goto ccc;
    cout << "第5个程序员的编号" << endl;
    
    
    cout << endl;
    
    // goto死循环:
    cout << "第1个程序员的编号" << endl;
    // aaa:
    cout << "第2个程序员的编号" << endl;
    cout << "第3个程序员的编号" << endl;
    cout << "第4个程序员的编号" << endl;
    // goto aaa;
    cout << "第5个程序员的编号" << endl;
    
    
    
    
    
    cout << endl;
}
