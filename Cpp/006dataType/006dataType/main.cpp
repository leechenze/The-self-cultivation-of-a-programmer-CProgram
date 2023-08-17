//
//  main.cpp
//  006dataType
//
//  Created by Lee ChenZe on 8/16/23.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    
    /** =========sizeof========= */
    cout << "sizeof(int)" << sizeof(int) << endl;
    cout << "sizeof(float)" << sizeof(float) << endl;
    cout << "sizeof(double)" << sizeof(double) << endl;
    cout << "sizeof(string)" << sizeof(string) << endl;
    cout << "sizeof(char)" << sizeof(char) << endl;
    cout << "sizeof(bool)" << sizeof(bool) << endl;
    
    int i;
    cout << "sizeof(i)" << sizeof(i) << endl;
    float f;
    cout << "sizeof(f)" << sizeof(f) << endl;
    double d;
    cout << "sizeof(d)" << sizeof(d) << endl;
    char c;
    cout << "sizeof(c)" << sizeof(c) << endl;
    string s;
    cout << "sizeof(s)" << sizeof(s) << endl;
    
    
    cout << endl;
    /** =========整型的基本概念========= */
    // short 在mac系统下是两个字节占用 取值范围是 -32767 ~ 32767
    // unsigned short 在mac系统下是两个字节占用 取值范围是 65535 ~ 65535
    short ssi = 1000;
    unsigned short usi = 65535;
    unsigned short usi1 = 65535 + 1;
    unsigned short usi2 = 65535 + 2;
    unsigned short usi3 = 65535 + 3;
    unsigned short usi100 = 65535 + 100;

    cout << "ssi = " << ssi << endl;
    cout << "usi = " << usi << endl;
    cout << "usi1 = " << usi1 << endl;
    cout << "usi2 = " << usi2 << endl;
    cout << "usi3 = " << usi3 << endl;
    cout << "usi100 = " << usi100 << endl;
    
    
    cout << endl;
    /** =========整数的书写========= */
    // 十进制
    int a = 100;
    cout << "十进制:a = " << a << endl;
    // 二进制
    int aa = 0b101;
    int bb = -0b110010;
    int cc = 0B100001;
    cout << "二进制:aa = " << aa << endl;
    cout << "二进制:bb = " << bb << endl;
    cout << "二进制:cc = " << cc << endl;
    // 八进制
    int aaa = 015;
    int bbb = -0101;
    int ccc = 0177777;
    cout << "八进制:aaa = " << aaa << endl;
    cout << "八进制:bbb = " << bbb << endl;
    cout << "八进制:ccc = " << ccc << endl;
    // 十六进制
    int aaaa = 0x2a;
    int bbbb = -0xa0;
    int cccc = 0xffff;
    cout << "十六进制:aaaa = " << aaaa << endl;
    cout << "十六进制:bbbb = " << bbbb << endl;
    cout << "十六进制:cccc = " << cccc << endl;
    
    
    cout << endl;
    /** =========long-long类型========= */
    // TODO
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    cout << endl;
}
