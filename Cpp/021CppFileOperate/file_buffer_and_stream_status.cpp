//
// Created by Lee ChenZe on 5/31/25.
//
#include <iostream>;
#include <fstream>;
#include <string>;
#include <unistd.h>;

using namespace std;

void file_buffer_and_stream_status() {
    cout << endl << "========================file_buffer_and_stream_status========================" << endl;


    cout << endl << "========================文件缓冲区========================" << endl;
    // string filename = "/Users/lee/MySkills/The-self-cultivation-of-a-programmer-CProgram/Cpp/021CppFileOperate/fileOutDir/text.txt";
    // ofstream fout(filename, ios::out);
    // for(int i = 0; i < 1000; i++) {
    //     fout << "i = " << i << ", I am bryant\n";
    //     // 刷新缓冲区, 这个方法的效果就是，没插入一条就会实时更新一条，而不等待缓冲区满了才写入一批到磁盘的数据。
    //     fout.flush();
    //     // 睡眠十分之一秒
    //     usleep(100000);
    // }
    //
    // fout.close();

    cout << endl << "========================流状态========================" << endl;

    string filename = "/Users/lee/MySkills/The-self-cultivation-of-a-programmer-CProgram/Cpp/021CppFileOperate/fileOutDir/text.txt";
    ifstream fin(filename, ios::in);
    if(fin.is_open() == false){
        cout << "打开文件" << filename << "失败" << endl;
    }
    string buffer;
    // while (getline(fin, buffer)) {
    //     cout << "buffer = " << buffer << endl;
    // }
    // 在c语言中，读取文件的流程本来就是应该这么写的，文件的位置指针如果到了末尾，eof的标志位就会被设置为1，c语言中都是通过eof为1进行判断的。
    // cpp做了封装，才有了上面的那种写法。
    while(1) {
        fin >> buffer;
        cout << "eof()=" << fin.eof() << ",good() = " << fin.good() << ", bad() = " << fin.bad() << ", fail() = "
             << fin.fail() << endl;
        if(fin.eof() == true) break;
        cout << "buffer = " << buffer << endl;
    }

    cout << endl << "========================file_buffer_and_stream_status========================" << endl;
}
