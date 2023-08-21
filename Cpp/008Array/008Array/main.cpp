//
//  main.cpp
//  008Array
//
//  Created by Lee ChenZe on 8/20/23.
//

#include <iostream>
using namespace std;

void func(int arr[], int len);
int compasc(const void* p1, const void* p2);
int compdesc(const void* p1, const void* p2);
int search(int arr[], int len, int key);

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
    // 创建8个元素的整型数组
    int *arr9 = new int[8];
    for (int i = 0; i < 8; i++) {
        arr9[i] = 100 + i;
        cout << "arr9[" << i << "] = " << *(arr9 + i) << endl;
    };
    delete []arr9;
    // (std::nothrow)的应用:在内存不足时返回nullptr,不会产生异常终止程序.
    int *arr10 = new (nothrow) int[100000000000001];
    if(arr10 == nullptr) {
        cout << "内存不足,分配失败" << endl;
    }else{
        arr10[10000000] = 8;
        delete[] arr10;
    }
    
    
    cout << endl;
    /** =========数组排序========= */
    int arr11[] = {3,5,6,4,5,1,2,9,7,8};
    cout << sizeof(arr11) << endl;
    qsort(arr11, sizeof(arr11)/sizeof(int),sizeof(int),compasc);
    qsort(arr11, sizeof(arr11)/sizeof(int),sizeof(int),compdesc);
    for(int i = 0; i < sizeof(arr11)/sizeof(int); i++) {
        cout << "arr11[" << i << "] = " << arr11[i] << endl;
    };
    
    
    cout << endl;
    /** =========数组查找========= */
    // 必须是已排好序的数组。
    int arr12[10] = { 7,9,12,16,21,25,30,35,41,48 };
    if (search(arr12, 10, 30) >= 0)
        cout << "在数组a中查找30成功,在数组中的索引是" << search(arr12, 10, 30) << endl;
    else cout << "在数组a中查找30失败。\n";

    
    cout << endl;
    /** =========C的字符串========= */
    // cpp字符串
    string str = "XYZ";
    cout << "str[0]" << (int)str[0] << endl;
    cout << "str[1]" << (int)str[1] << endl;
    cout << "str[2]" << (int)str[2] << endl;
    cout << "str[3]" << (int)str[3] << endl;
    // 初始方法
    char str1[11];
    cout << "str1[0] = " << (int)str1[0] << endl;
    char str2[11] = "hello";
    char str3[] = {"hello"};
    char str4[11] = {"hello"};
    char str5[11]{"hello"};
    cout << "str1[0] = " << (int)str1[0] << endl;
    cout << "str4[0] = " << (int)str4[0] << endl;
    cout << "str5[0] = " << (int)str5[0] << endl;
    // 清空字符串
    char str6[11] = {0};
    // 虽然在linux平台下显示的都是很干净的0值,但是在windows平台下都是一些乱码的垃圾值;
    // memset可以对与字符串的每一位置为0,也可以达到清空字符串的效果.
    char str7[5];
    memset(str7,0,sizeof(str7));
    cout << "str7[0] = " << (int)str7[0] << endl;
    cout << "str7[1] = " << (int)str7[1] << endl;
    cout << "str7[2] = " << (int)str7[2] << endl;
    cout << "str7[3] = " << (int)str7[3] << endl;
    cout << "str7[4] = " << (int)str7[4] << endl;
    // 字符串复制或赋值
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
int compasc(const void* p1, const void* p2){
    // if(*((int*)p1) < (*(int*)p2)) return -1;
    // if(*((int*)p1) == (*(int*)p2)) return 0;
    // if(*((int*)p1) > (*(int*)p2)) return 1;
    // 以上步骤可以简写为
    return *(int*)p1 - *(int*)p2;
}
int compdesc(const void* p1, const void* p2){
    // if(*((int*)p1) < (*(int*)p2)) return -1;
    // if(*((int*)p1) == (*(int*)p2)) return 0;
    // if(*((int*)p1) > (*(int*)p2)) return 1;
    // 以上步骤可以简写为
    return *(int*)p2 - *(int*)p1;
}
int search(int arr[], int len, int key){
    int low = 0, high = len-1,mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        // 查找成功。
        if (arr[mid] == key) return mid;
        // 继续在前半区查找。
        else if (arr[mid] > key) high = mid - 1;
        // 继续在后半区查找。
        else low = mid + 1;
    }
    // 查找失败。
    return -1;
}
