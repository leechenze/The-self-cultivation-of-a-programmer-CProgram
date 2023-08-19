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
    long aaaaa = 9223372036854775807;
    long bbbbb = 9223372036854775808;
    long long ccccc = 9223372036854775808;
    cout << "sizeof(aaaaa) = " << sizeof(aaaaa) << ", aaaaa = " << aaaaa << endl;
    cout << "sizeof(bbbbb) = " << sizeof(bbbbb) << ", bbbbb = " << bbbbb << endl;
    cout << "sizeof(ccccc) = " << sizeof(ccccc) << ", ccccc = " << ccccc << endl;
    
    
    cout << endl;
    /** =========浮点数========= */
    cout << "sizeof(float) = " << sizeof(float) << endl;
    cout << "sizeof(double) = " << sizeof(double) << endl;
    cout << "sizeof(long double) = " << sizeof(long double) << endl;
    
    // 最后加一个f用以表示该小数是float类型.
    float x = 123.456789f;
    double y = 12345678912345.6789123456789;
    long double z = 12345678912345.6789123456789;
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
    cout << "z = " << z << endl;
    cout << "使用C的printf输出" << endl;
    printf("x = %f \n", x);
    printf("y = %lf \n", y);
    printf("z = %lf \n", z);
    
    
    cout << endl;
    /** =========字符型的基本概念========= */
    char xx = 'X';
    cout << "xx = " << xx <<endl;
    cout << "sizeof(xx) = " << sizeof(xx) << endl;
    // 'X'对应的ASCII码值是88, 用char声明就会输出为X字符.
    char xxx = 88;
    cout << "xxx = " << xxx <<endl;
    cout << "(char)xxx = " << (char)xxx <<endl;
    cout << "(int)xxx = " << (int)xxx <<endl;
    // 同理,字符也可以用 int 进行声明.
    int xxxx = 'X';
    cout << "(char)xxxx = " << (char)xxxx <<endl;
    cout << "(int)xxxx = " << (int)xxxx <<endl;
    // 可以用char与整数进行任何运算
    char yy = 'Y' + 3;
    cout << "yy = " << yy << endl;
    cout << "(int)yy = " << (int)yy << endl;
    
    
    cout << endl;
    /** =========转义字符========= */
    cout << "1\ttrump\n";
    cout << "100\tobama\n";
    cout << "1000\thillary\n";
    
    
    cout << endl;
    /** =========Cpp11原始字面量========= */
    string path = "\\Users\\xxx\\MySkills\\course\\Cpp\\006dataType\\006dataType";
    string path1 = R"(\Users\xxx\MySkills\course\Cpp\006dataType\006dataType)";
    // 给R字面量加一个标签:abc,相当于程序中的注释,不会被输出,注意标签语法要保证前后一致,否则会报错.
    string path2 = R"abc(\Users\xxx\MySkills\course\Cpp\006dataType\006dataType)abc";
    cout << "path is " << path << endl;
    cout << "path1 is " << path1 << endl;
    cout << "path2 is " << path2 << endl;
    // 原始字面量更方便的输出xml格式的内容.
    string strInfo = "\
            <no>trump</no>\
            <weight>200kg</weight>\
            <height>196cm</height>\
            <age>88</age>\
        ";
    cout << "strInfo = " << endl << strInfo << endl;
    string strInfo1 = R"(
            <no>trump</no>
            <weight>200kg</weight>
            <height>196cm</height>
            <age>88</age>
        )";
    cout << "strInfo1 = " << strInfo1 << endl;
    
    
    cout << endl;
    /** =========字符串型========= */
    // string str1 = "111"+"222"+"333";
    string str = "111""222""333";
    cout << "str = " << str << endl;
    
    
    cout << endl;
    /** =========布尔型========= */
    bool tu = true,fa = false;
    cout << "sizeof(bool) = " << sizeof(bool) << endl;
    cout << "tu = " << tu << ", fa = " << fa << endl;
    cout << "tu + fa = " << tu + fa << endl;
    
    
    cout << endl;
    /** =========数据类型转换========= */
    char a1 = 30;
    int b1 = 102400;
    long long c1 = 150000000000000001;
    // 如下运算会隐私将char型的a1 和 int型的b1相加的结果自动转换为 c1 的 long long型
    // 因为long long类型是精度最高的,不会出错.反之c1的long long型转为char或int都不可行.
    cout << "a1+b1+c1 = " << a1+b1+c1 << endl;
    // 强制类型转换
    cout << "8 / 5 = " << 8 / 5 << endl;
    cout << "(int)8 / 5 = " << (int)8 / 5 << endl;
    cout << "(double)8 / 5 = " << (double)8 / 5 << endl;
    
    
    cout << endl;
    /** =========数据类型别名========= */
    typedef unsigned int uint;
    typedef long long llong;
    typedef unsigned long long ullong;
    
    uint a3 = 1024;
    llong b3 = 384772;
    ullong c3 = 3847582345295893;
    cout << "sizeof(uint)" << sizeof(uint) << ", a3 = " << a3 << endl;
    cout << "sizeof(llong)" << sizeof(llong) << ", b3 = " << b3 << endl;
    cout << "sizeof(ullong)" << sizeof(ullong) << ", c3 = " << c3 << endl;
    // 像如下创建别名的代码在实际开发中一般放在头文件中.
    // 在VS中，short是两个字节，int是四个字节，long也是四个字节，long long是八个字节。
    typedef short           int16_t;    // 16位的整数。
    typedef int             int32_t;    // 32位的整数。
    typedef long long       int64_t;    // 64位的整数。
    // 在Linux中，short是两个字节，int是四个字节，long也是八个字节，long long也是八个字节。
    typedef short           int16_t;    // 16位的整数。
    typedef int             int32_t;    // 32位的整数。
    typedef long            int64l_t;    // 64位的整数。
    // 在程序源代码中，只使用别名int16_t、int32_t、int64_t，不使用原名。
    
    
    cout << endl;
}
