//
// Created by Lee ChenZe on 5/31/25.
//
#include <iostream>;
#include <fstream>;
#include <string>;

using namespace std;

void random_access() {
    cout << endl << "========================random_access========================" << endl;


    cout << endl << "========================fstream替换ifstream和ofstream========================" << endl;

    // string filename = "/Users/lee/MySkills/The-self-cultivation-of-a-programmer-CProgram/Cpp/021CppFileOperate/fileOutDir/text.txt";
    // fstream fout;
    // fstream fin;
    // string buffer;
    // fout.open(filename, ios::out);
    // fin.open(filename, ios::in);
    // if(fout.is_open() == false || fin.is_open() == false) {
    //     cout << "打开文件" << filename << "失败" << endl;
    // }
    //
    // fout << "douglas|25|Extremely handsome" << endl;
    // fout << "beckham|20|Handsome" << endl;
    // fout << "hamilton|30|General" << endl;
    // fout << endl;
    //
    // while (getline(fin, buffer)) {
    //     cout << "buffer = " << buffer << endl;
    // }
    //
    // fout.close();
    // fin.close();

    cout << endl << "========================随机存取-tellp和tellg方法========================" << endl;

    // string filename = "/Users/lee/MySkills/The-self-cultivation-of-a-programmer-CProgram/Cpp/021CppFileOperate/fileOutDir/text.txt";
    // ofstream fout;
    // fout.open(filename, ios::out);
    // if(fout.is_open() == false) {
    //     cout << "打开文件" << filename << "失败" << endl;
    // }
    //
    // cout << "位置 = " << fout.tellp() << endl;
    // fout << "douglas|25|Extremely handsome" << endl;
    // cout << "位置 = " << fout.tellp() << endl;
    // fout << "beckham|20|Handsome" << endl;
    // cout << "位置 = " << fout.tellp() << endl;
    // fout << "hamilton|30|General" << endl;
    // cout << "位置 = " << fout.tellp() << endl;
    // fout << endl;
    //
    // fout.close();

    cout << endl << "========================随机存取-seekg和seekp方法========================" << endl;

    // // 移动文件位置的读和写操作
    // string filename = "/Users/lee/MySkills/The-self-cultivation-of-a-programmer-CProgram/Cpp/021CppFileOperate/fileOutDir/text.txt";
    // fstream fs;
    // fs.open(filename, ios::in|ios::out);
    // if (fs.is_open() == false) {
    //     cout << "打开文件" << filename << "失败" << endl;
    // }
    //
    // // 手动移动指针
    // fs.seekg(10);
    //
    // // 写入移动指针后的文件内容
    // fs << " insert data for Bryant " << endl;
    //
    // // // 读取移动指针后的文件内容
    // // string buffer;
    // // while(fs >> buffer) {
    // //     cout << "buffer = " << buffer << endl;
    // // }
    //
    // fs.close();

    cout << endl << "========================random_access========================" << endl;
}
