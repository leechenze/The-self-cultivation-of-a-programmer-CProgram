//
//  main.cpp
//  002arithmetic
//
//  Created by Lee ChenZe on 8/12/23.
//

#include <iostream>

using namespace std;

int main() {
    cout << endl;
    /** =========算术运算========= */
    int a = 8;
    int b = 4;
    double c = 8.8;
    double d = 4.3;
    
    cout << a + b << endl;
    cout << a - b << endl;
    cout << a * b << endl;
    cout << a / b << endl;
    cout << a % b << endl;
    
    cout << endl;
    
    cout << c + d << endl;
    cout << c - d << endl;
    cout << c * d << endl;
    cout << c / d << endl;
    cout << a % b << endl;
    
    
    
    
    
    cout << endl;
    /** =========自增和自减========= */
    int i = 10;
    int e;
    
    
    e = i++;
    // 等同于
    // e = i;
    // i = i + 1;
    cout << "i = " << i << endl;
    cout << "e = " << e << endl;
    
    
    e = ++i;
    // 等同于
    // i = i + 1;
    // e = i;
    cout << "i = " << i << endl;
    cout << "e = " << e << endl;
    
    
    
    
    
    
    cout << endl;
    /** =========赋值运算符========= */
    int f = 10;
    int g = 20;
     f += g;
    // f -= g;
    // f *= g;
    // f /= g;
    // f %= g;
    cout << "f = " << f << endl;
    
    
    
    
    
    
    cout << endl;
    /** =========C++11初始化赋值========= */
    // C++ 标准
    int h = 10;
    int j = (10);
    int k (10);
    
    // C++11 标准
    int h1 = 10;
    int j1 = {10};
    int k1 {10};
    
    cout << "h = " << h << endl;
    cout << "j = " << j << endl;
    cout << "k = " << k << endl;
    
    cout << "h1 = " << h1 << endl;
    cout << "j1 = " << j1 << endl;
    cout << "k1 = " << k1 << endl;
    
    
    
    
    
    
    
    
    cout << endl;
    /** =========关系运算========= */
    int l = 8;
    int m = 8;
    bool res;
    
    // res = l == m;
    // res = l != m;
    // res = l < m;
     res = l <= m;
    
    cout << "res = " << res << endl;
    cout << "res = " << (l == m) << endl;
    
    
    
    
    
    
    
    cout << endl;
    /** =========逻辑运算========= */
    bool n = false;
    bool o = true;
    bool res1 = n && o;
    bool res2 = n || o;
    
    cout << "res1 = " << res1 << endl;
    cout << "n && o = " << (n && o) << endl;
    cout << "res2 = " << res2 << endl;
    cout << "n || o = " << (n || o) << endl;
    cout << "!n = " << (!n) << endl;
    
    
    
    
    
    
    
    
    cout << endl;
    /** =========逗号运算========= */
    int p = 1, q = 2;
    cout << "p = " << p << endl;
    cout << "q = " << q << endl;
    
    
    
    
    
    
    cout << endl;
}
