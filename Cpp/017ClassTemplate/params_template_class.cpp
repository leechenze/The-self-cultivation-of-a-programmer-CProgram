//
// Created by Lee ChenZe on 10/26/24.
//

#include <iostream>

using namespace std;


template<class T, int len>
class LinkList             // 链表类模板。
{
public:
    T *m_head;          // 链表头结点。
    int m_len = len;   // 表长。
    void insert() { cout << "向链表中插入了一条记录。\n"; }

    void ddelete() { cout << "向链表中删除了一条记录。\n"; }

    void update() { cout << "向链表中更新了一条记录。\n"; }
};

template<class T, int len>
class Array                // 数组类模板。
{
public:
    T *m_data;          // 数组指针。
    int m_len = len;   // 表长。
    void insert() { cout << "向数组中插入了一条记录。\n"; }

    void ddelete() { cout << "向数组中删除了一条记录。\n"; }

    void update() { cout << "向数组中更新了一条记录。\n"; }
};

// 线性表模板类：tabletype-线性表类型，datatype-线性表的数据类型。
template<template<class, int> class tabletype, class datatype, int len>
class LinearList {
public:
    tabletype<datatype, len> m_table;     // 创建线性表对象。

    void insert() { m_table.insert(); }         // 线性表插入操作。
    void ddelete() { m_table.ddelete(); }      // 线性表删除操作。
    void update() { m_table.update(); }      // 线性表更新操作。

    void oper()     // 按业务要求操作线性表。
    {
        cout << "len=" << m_table.m_len << endl;
        m_table.insert();
        m_table.update();
    }
};


void params_template_class() {
    cout << endl << "========================params_template_class========================" << endl;

    // 创建线性表对象，容器类型为链表，链表的数据类型为int，表长为20。
    LinearList<LinkList, int, 20> a;
    a.insert();
    a.ddelete();
    a.update();

    // 创建线性表对象，容器类型为数组，数组的数据类型为string，表长为20。
    LinearList<Array, string, 20> b;
    b.insert();
    b.ddelete();
    b.update();


    cout << endl << "========================params_template_class========================" << endl;
}
