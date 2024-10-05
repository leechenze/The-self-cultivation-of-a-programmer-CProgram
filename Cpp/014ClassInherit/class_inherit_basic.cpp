//
// Created by Lee ChenZe on 10/5/24.
//
#include "iostream"

using namespace std;


class CAllComers          // 海选报名者类
{
public:
    string m_name;          // 姓名
    string m_tel;           // 联系电话

    // 构造函数。
    CAllComers() {
        m_name = "某女";
        m_tel = "不详";
    }

    // 报名时需要唱一首歌。
    void sing() { cout << "我是一只小小鸟。\n"; }

    // 设置姓名。
    void setname(const string &name) { m_name = name; }

    // 设置电话号码。
    void settel(const string &tel) { m_tel = tel; }
};


class CGirl : public CAllComers {
public:
    int m_bh;

    CGirl() {
        m_bh = 8;
    }

    void show() {
        cout << "编号: " << m_bh << ",姓名: " << m_name << ", 联系电话: " << m_tel << endl;
    }

};





void class_inherit_basic() {
    cout << endl;

    CGirl cGirl;
    cGirl.setname("西施");
    cGirl.show();

    cout << "==========================class_inherit_basic==========================" << endl;
}