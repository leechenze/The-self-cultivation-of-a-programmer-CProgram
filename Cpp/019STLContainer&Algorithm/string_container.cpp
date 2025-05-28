//
// Created by Lee ChenZe on 5/26/25.
//
#include <iostream>;

using namespace std;

void string_container() {
    cout << endl << "========================string_container========================" << endl;

    // 最大字符数组的最大长度
    cout << "npos = " << string::npos << endl;

    /** 创建一个长度为0的string对象（默认构造函数）。*/
    // // string();
    // string s1;
    // cout << "s1 = " << s1 << endl;
    // // 返回当前容量, 可以存放字符的总数.
    // cout << "s1.capacity() = " << s1.capacity() << endl;
    // // 返回容器中数据的大小.
    // cout << "s1.size() = " << s1.size() << endl;

    /** 将string对象初始化为s指向的NBTS（转换函数）。*/
    // // string(const char *s);
    // string s2("hello world!");
    // cout << "s2 = " << s2 << endl;
    // string s3 = "hello world!";
    // cout << "s3 = " << s3 << endl;

    /** 将string对象初始化为str（拷贝构造函数）。*/
    // // string(const string &str);
    // string s4(s3);
    // cout << "s4 = " << s4 << endl;
    // string s5 = s3;
    // cout << "s5 = " << s5 << endl;

    /** 将string对象初始化为s指向的地址后n字节的内容。*/
    // // string(const char *s,size_t n);
    // string s6("hello world!", 5);
    // cout << "s6 = " << s6 << endl;
    // string s7("hello world!", 50);
    // cout << "s7 = " << s7 << endl;

    /** 将sring对象初始化为str从位置pos开始到结尾的字符（或从位置pos开始的n个字符）。*/
    // // string(const string &str,size_t pos=0,size_t n=npos);
    // string s8(s3, 3, 5);
    // cout << "s8 = " << s8 << endl;
    // string s9(s3, 3);
    // string s10(s3, 3, 50);
    // cout << "s9 = " << s9 << endl;
    // cout << "s10 = " << s10 << endl;
    // cout << "s9.capacity() = " << s9.capacity() << endl;
    // cout << "s9.size() = " << s9.size() << endl;


    /** 将string对象初始化为区间[begin,end]内的字符，其中begin和end的行为就像指针，用于指定位置，范围包括begin在内，但不包括end。*/
    // template<class T> string(T begin,T end);

    /** 创建一个由n个字符c组成的string对象。*/
    // // string(size_t n,char c);
    // string s11(8, 'x');
    // cout << "s11 = " << s11 << endl;
    // string s12(30, 0);
    // cout << "s12 = " << s12 << endl;


    cout << endl << "========================用string容器存放结构体数据========================" << endl;
    // 定义结构体
    struct st_girl{
        int bh;
        char name[30];
        bool yz;
        double weight;
        string memo;
    } girl;

    cout << "超女结构体大小: " << sizeof(struct st_girl) << endl;

    // 创建一个空的string容器: buffer;
    string buffer;
    for (int ii = 1; ii <= 10; ii++) {
        // 对超女结构体成员赋值
        memset(&girl, 0, sizeof girl);
        girl.bh = ii;
        sprintf(girl.name, "西施%02d", ii);
        girl.yz = true;
        girl.weight = 48.5 + ii;
        girl.memo = "中国第一美女";

        // 把结构体追加到buffer中
        buffer.append((char *)&girl, sizeof(struct st_girl));
    }

    // 显示容量
    cout << "buffer.capacity() = " << buffer.capacity() << endl;
    // 显示实际大小
    cout << "buffer.size() = " << buffer.size() << endl;

    // 再用一个循环把buffer中的数据全部取出来
    for(int ii = 0; ii < buffer.size() / sizeof (struct st_girl); ii++){
        // 初始化超女结构体
        memset(&girl, 0 , sizeof(struct st_girl));
        // 把容器中的数据赋值给超女结构体
        memcpy(&girl, buffer.data() + ii * sizeof(struct st_girl), sizeof(struct st_girl));
        // 显示超女结构体成员的值
        cout << "bh=" << girl.bh << ",name=" << girl.name << ",yz=" << girl.yz << ",weight="
             << girl.weight << ",memo=" << girl.memo << endl;
    }


    cout << endl << "========================string_container========================" << endl;
}