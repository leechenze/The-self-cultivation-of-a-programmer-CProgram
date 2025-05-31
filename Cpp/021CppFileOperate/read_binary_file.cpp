//
// Created by Lee ChenZe on 5/31/25.
//
#include <iostream>;
#include <fstream>;
#include <string>;

using namespace std;

void read_binary_file() {
    cout << endl << "========================read_binary_file========================" << endl;

    string filename = "/Users/lee/MySkills/The-self-cultivation-of-a-programmer-CProgram/Cpp/021CppFileOperate/fileOutDir/binary.txt";
    ifstream fin;
    fin.open(filename, ios::in | ios::binary);

    if(fin.is_open() == false) {
        cout << "打开文件" << filename << "失败" << endl;
    }

    // 二进制文件以数据块(数据类型)的形式读取数据，而不是向文本文件那样，以每一行的形式读取
    // 即，存进去的时候是什么格式，读取时就要定义什么格式
    struct st_boy {
        char name[31];
        int no;
        char memo[301];
        double weight;
    } boy;

    // 读取文件
    while (fin.read((char *) &boy, sizeof(boy))) {
        cout << "name=" << boy.name << "，no=" << boy.no <<
             "，memo=" << boy.memo << "，weight=" << boy.weight << endl;
    }

    fin.close();
    
    cout << "操作文件完成" << endl;

    cout << endl << "========================read_binary_file========================" << endl;
}
