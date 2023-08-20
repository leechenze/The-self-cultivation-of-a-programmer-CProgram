//
//  main.cpp
//  007PointersAndMemory
//
//  Created by Lee ChenZe on 8/19/23.
//

#include <iostream>
using namespace std;

void func1(int* no, string* msg);
void func2(int a, int b, int c, int* max, int* min);
void func3(int** pp);
void func4(int* no, string* msg);
int* func5();
void func6(int no, string msg);
//
void func7(void (*pf)());
void func7001();
void func7002();
void func7003();
void func7004();
void func8(void (*pf)(string));
void func8001(string);
void func9(void (*pf)(string),string component);
void func9001(string);


int main(int argc, const char * argv[]) {
    
    cout << endl;
    /** =========指针的基本概念========= */
    int a;
    char b;
    bool c;
    string d;
    
    cout << "变量a的地址是:" << &a << endl;
    cout << "变量b的地址是:" << &b << endl;
    cout << "变量c的地址是:" << &c << endl;
    cout << "变量d的地址是:" << &d << endl;
    
    cout << endl;
    cout << "变量a的地址是:" << (void*)&a << endl;
    cout << "变量b的地址是:" << (void*)&b << endl;
    cout << "变量c的地址是:" << (void*)&c << endl;
    cout << "变量d的地址是:" << (void*)&d << endl;
    
    cout << endl;
    cout << "变量a的地址是:" << (long long)&a << endl;
    cout << "变量b的地址是:" << (long long)&b << endl;
    cout << "变量c的地址是:" << (long long)&c << endl;
    cout << "变量d的地址是:" << (long long)&d << endl;
    
    int *pa = &a;
    char *pb = &b;
    bool *pc = &c;
    string *pd = &d;
    cout << endl;
    // 指针默认是用十六进制表示的,不过为了方便我们都用 long long 转为十进制.
    cout << "指针pa的值是:" << (long long)pa << endl;
    cout << "指针pb的值是:" << (long long)pb << endl;
    cout << "指针pc的值是:" << (long long)pc << endl;
    cout << "指针pd的值是:" << (long long)pd << endl;
    
    
    cout << endl;
    /** =========使用指针========= */
    int a1 = 3;
    int* p1 = &a1;
    int* p2 = &a1;
    cout << "a1 = " << a1 << endl;
    cout << "*p1 = " << *p1 << endl;
    // 如下等同于 a1 = 8, 推理一下, 过程如下:
    // p1 == &a1
    // *p1 == *&a1 == a1
    *p1 = 8;
    cout << "a1 = " << a1 << endl;
    cout << "*p1 = " << *p1 << endl;
    cout << "*p2 = " << *p2 << endl;
    
    
    cout << endl;
    /** =========指针用于函数的参数========= */
    int a2 = 3;
    string messages = "我是一只小小鸟";
    
    // func1代码中参数为引用内存地址
    func1(&a2, &messages);
    cout << "亲爱的" << a2 << "号超女:" << messages << endl;
    // 模拟代码,即func1函数中的那些代码.
    {
        // int* no = &a2;
        // string* msg = &messages;
        // cout << "亲爱的" << *no << "号超女:" << *msg << endl;
        // *no = 8;
        // *msg = "我是刘德华";
        // cout << "亲爱的" << a2 << "号超女:" << messages << endl;
    }
    // 实际开发中对修改函数中实参值的应用场景非常多,如下例子:
    // 这个例子用于求a3, b3, c3中的最大值和最小值.
    int a3 = 180, b3 = 170, c3 = 175, largest,smallest;
    func2(a3, b3, c3, &largest, &smallest);
    cout << "largest = " << largest << ", smallest = " << smallest << endl;
    
    
    cout << endl;
    /** =========用const修饰指针========= */
    // 常量指针：指针指向可以改，指针指向的值不可以更改。
    int a4 = 3,b4 = 8;
    const int* p4 = &a4;
    cout << "a4 = " << a4 << ", *p4 = " << *p4 << endl;
    p4 = &b4;
    cout << "b4 = " << b4 << ", *p4 = " << *p4 << endl;
    // 指针常量：指针指向不可以改，指针指向的值可以更改。
    int* const p5 = &a4;
    *p5 = 10;
    cout << "a4 = " << a4 << ", *p5 = " << *p5 << endl;
    
    
    cout << endl;
    /** =========void关键字========= */
    cout << endl;
    /** =========Cpp内存模型========= */
    cout << endl;
    /** =========动态分配内存new和delete========= */
    int *p6 = new int{10};
    cout << "*p6 = " << *p6 << endl;
    *p6 = 8;
    cout << "*p6 = " << *p6 << endl;
    delete p6;
    
    
    cout << endl;
    /** =========二级指针========= */
    int ii = 8;
    cout << "ii = " << ii << ", ii的地址是" << &ii << endl;
    int *pii = &ii;
    cout << "pii = " << pii << ", pii的地址是" << &pii << ",*pii = " << *pii << endl;
    int **ppii = &pii;
    cout << "ppii = " << ppii << ", ppii的地址是" << &ppii << ",*ppii = " << *ppii << endl;
    cout << "**ppii = " << **ppii << endl;
    // 应用场景
    int* p7 = 0;
    func3(&p7);
    cout << "p7 = " << p7 << ", *p7 = " << *p7 << endl;
    
    
    cout << endl;
    /** =========空指针========= */
    int* p8 = 0;
    // c++11 标准的空指针可以用 nullptr 关键字定义.
    p8 = nullptr;
    cout << "p8 = " << p8 << ", *p8 = 错误" << endl;
    delete p8;
    cout << "delete p8" << endl;
    // 错误常见场景(传入空指针时进行容错处理,func4函数内容和func1是一样的,只是加了一个容错判断)
    int* no = 0;
    string* message = 0;
    func4(no,message);
    
    
    cout << endl;
    /** =========野指针========= */
    // 错误常见场景
    int* p9 = func5();
    // 如下 p9 地址是正确的, 但 *p9 解引用后的值是不正确的.
    cout << "p9 = " << p9 << ", *p9 = " << *p9 << endl;
    
    
    cout << endl;
    /** =========函数指针和回调函数========= */
    int no10 = 10;
    string msg10 = "我是Obama";
    func6(no10, msg10);
    // 声明函数指针
    void (*pf10)(int, string);
    // 函数指针赋值
    pf10 = func6;
    // 调用函数指针(C语法)
    (*pf10)(no10, msg10);
    // 调用函数指针(C++语法)
    pf10(no10, msg10);
    // 应用场景(一台电脑主机的生产线组装工作流程)
    func7(func7001);
    cout << endl;
    func8(func8001);
    cout << endl;
    func9(func9001, "网络接口器");
    
    
    
    
    
    
    
    cout << endl;
    cout << endl;
    cout << endl;
}





void func1(int* no, string* msg) {
    cout << "func1:亲爱的" << *no << "号超女:" << *msg << endl;
     *no = 8;
     *msg = "我是蔡徐坤";
}
void func2(int a, int b, int c, int* max, int* min){
    *max = a > b ? a : b;           // 取a和b中的大者
    *min = a < b ? a : b;           // 取a和b中的小者
    *max = *max > c ? *max : c;     // 取max和c中的大者
    *min = *min < c ? *min : c;     // 取min和c中的小者
}
void func3(int** pp7){
    *pp7 = new int(10);
    cout << "pp7 = " << pp7 << ", *pp7 = " << *pp7 << endl;
}
void func4(int* no, string* msg) {
    if(no == 0 || msg == 0) {
        cout << "空指针异常!" << endl;
        return;
    }
    cout << "func1:亲爱的" << *no << "号超女:" << *msg << endl;
     *no = 8;
     *msg = "我是蔡徐坤";
}
int* func5() {
    int a = 30;
    cout << "a = " << a << ", &a = " << &a << endl;
    return &a;
};
void func6(int no, string msg) {
    cout << "func1:亲爱的" << no << "号超女:" << msg << endl;
};
void func7(void (*pf)()) {
    cout << "固定流程的机箱组装工作开头" << endl;
    // 非固定流程的自定义中间工作
    pf();
    cout << "固定流程的机箱组装工作收尾" << endl;
};
void func7001() {
    cout << "自定义流程:组装CPU" << endl;
};
void func7002() {
    cout << "自定义流程:组装GPT" << endl;
};
void func7003() {
    cout << "自定义流程:组装板载内存" << endl;
};
void func7004() {
    cout << "自定义流程:组装硬盘" << endl;
};
void func8(void (*pf)(string)) {
    cout << "固定流程的机箱组装工作开头" << endl;
    string component = "散热器";
    // 非固定流程的自定义中间工作
    pf(component);
    cout << "固定流程的机箱组装工作收尾" << endl;
};
void func8001(string component) {
    cout << "自定义流程:组装" << component << endl;
};
void func9(void (*pf)(string),string component) {
    cout << "固定流程的机箱组装工作开头" << endl;
    // 非固定流程的自定义中间工作
    pf(component);
    cout << "固定流程的机箱组装工作收尾" << endl;
};
void func9001(string component) {
    cout << "自定义流程:组装" << component << endl;
};
