//
//  main.cpp
//  008Array
//
//  Created by Lee ChenZe on 8/20/23.
//

#include <iostream>
using namespace std;

void func(int arr[], int len);

int main(int argc, const char * argv[]) {
    cout << endl;
    /** =========数组的基本概念========= */
    int arr[5] = {3,6,1,4,7};
    int arr1[] = {3,6,1,4,7,0,22,12};
    int arr2[5] = {};
    string name[5];
    // 数组占用内存的情况
    cout << "sizeof(arr) = " << sizeof(arr) << endl;
    
    // 数组的内存占用大小 / 数组中单个值的内存占用大小 = 数组的长度
    for (int i = 0; i < sizeof(arr1)/sizeof(int); i++) {
        cout << arr1[i] << endl;
    };
    cout << endl;
    for (int i = 0; i < sizeof(arr2)/sizeof(int); i++) {
        cout << arr2[i] << endl;
    };
    // 清空数组(值都将清为零)
    memset(arr1, 0, sizeof(arr1));
    cout << endl;
    for (int i = 0; i < sizeof(arr1)/sizeof(int); i++) {
        cout << arr1[i] << endl;
    };
    // 复制数组
    int arr3[10] = {1,2,3,4,5,6,7,8,9,0};
    int arr4[sizeof(arr3)/sizeof(int)];
    memcpy(arr4,arr3,sizeof(arr3));
    cout << endl;
    for (int i = 0; i < sizeof(arr4)/sizeof(int); i++) {
        cout << arr4[i] << endl;
    };
    
    
    cout << endl;
    /** =========数组和指针========= */
    int arr5[5];
    cout << "arr5的值是 = " << (long long)arr5 << endl;
    cout << "arr5的地址是 = " << (long long)&arr5 << endl;
    for (int i = 0; i < 5; i++) {
        cout << "arr5[" << i << "]的地址是 = " << (long long)&arr5[i] << endl;
    };
    int* p1 = (int*)&arr5;
    cout << "p1的值是 = " << (long long)p1 << endl;
    for (int i = 0; i < 5; i++) {
        cout << "p1 + " << i << "的值是 = " << (long long)(p1 + i) << endl;
    };
    
    
    cout << endl;
    /** =========数组的越界========= */
    cout << endl;
    /** =========数组用于函数的参数========= */
    int arr6[5] = {0,1,2,3,4};
    int* p2 = (int*)&arr6;
    // 用数组表示法操作数组
    for (int i = 0; i < 5; i++) {
        cout << "arr6[ + " << i << "]的值是 = " << arr6[i] << endl;
    };
    cout << endl;
    // 用指针表示法操作数组
    for (int i = 0; i < 5; i++) {
        cout << "*(p2 + " << i << ")的值是 = " << *(p2 + i) << endl;
        cout << "p2[ + " << i << "]的值是 = " << p2[i] << endl;
    };
    // /////////骚操作1
    int arr7[] = {0,1,2,3,4,5};
    // 原因是数组第二个地址[0]解释为 *(第二个元素的地址 + 0)
    cout << (&arr7[2])[0] << endl;
    // 原因是数组第二个地址[0]解释为 *(第二个元素的地址 + 1)
    cout << (&arr7[2])[1] << endl;
    // 原因是数组第二个地址[0]解释为 *(第二个元素的地址 + 2)
    cout << (&arr7[2])[2] << endl;
    // /////////用于函数参数
    int arr8[] = {0,1,2,3,4,5,6};
    func(arr8, sizeof(arr8) / sizeof(int));
    
    
    cout << endl;
    /** =========用new动态创建数组========= */
    // TODO
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    cout << endl;
    cout << endl;
    cout << endl;
}




void func(int arr[], int len){
    for(int i = 0; i < len; i++) {
        cout << "arr[" << i << "]的值是" << arr[i] << endl;
    }
}
