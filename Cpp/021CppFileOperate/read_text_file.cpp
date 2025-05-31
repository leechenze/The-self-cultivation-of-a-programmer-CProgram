//
// Created by Lee ChenZe on 5/30/25.
//
#include <iostream>;
#include <fstream>;
#include <string>;

using namespace std;

void read_text_file() {
    cout << endl << "========================read_text_file========================" << endl;

    // 声明文件路径
    string filename = "/Users/lee/MySkills/The-self-cultivation-of-a-programmer-CProgram/Cpp/021CppFileOperate/fileOutDir/text.txt";
    // 创建文件输入流对象
    ifstream fin;
    fin.open(filename, ios::in);
    // 判断文件是否打开成功，只有当打开成功时才能读取文件.
    // 文件打开失败的原因主要有三种：目录不存在，磁盘空间已满，没有权限
    if (fin.is_open() == false) {
        cout << "打开文件" << filename << "失败" << endl;
    }

    // cout << "读取方式一" << endl;
    // // 读取文件内容: 方式一
    // // 定义用于存放文件中读取的内容的buffer
    // string buffer;
    // // 文本文件一般以行的方式读取文件
    // while(getline(fin, buffer)){
    //     cout << buffer << endl;
    // }
    // cout << endl;

    // cout << "读取方式二" << endl;
    // // 读取文件内容: 方式二
    // // 定义用于存放文件中读取的内容的buffer
    // char buffer1[110];
    // // 注意：如果采用ifstream.getline()一定要保证缓冲区足够大
    // while (fin.getline(buffer1, 100)) {
    //     cout << buffer1 << endl;
    // }
    // cout << endl;

    cout << "读取方式三" << endl;
    string buffer;
    while (fin >> buffer){
        cout << buffer << endl;
    }
    cout << endl;

    fin.close();

    cout << endl << "========================read_text_file========================" << endl;
}
