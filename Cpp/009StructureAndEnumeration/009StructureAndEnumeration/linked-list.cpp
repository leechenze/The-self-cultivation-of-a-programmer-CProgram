//
//  linked-list.cpp
//  009StructureAndEnumeration
//
//  Created by Lee ChenZe on 8/29/23.
//

#include <stdio.h>
#include <iostream>

using namespace std;

struct st_girl{
    int no;
    string name;
    struct st_girl *next;
};

void linked_list() {
    cout << endl;
    // 单链表操作
    // 创建head头指针, tail尾指针, tmp临时指针
    st_girl *head = nullptr, *tail = nullptr, *tmp = nullptr;
    // 分配第一个节点
    tmp = new st_girl({1,"hillary",nullptr});
    // 将tmp指针赋予头指针和尾指针
    head = tail = tmp;
    // 分配第二个节点
    tmp = new st_girl({2,"harris",nullptr});
    // 把上一个节点的next指针指向新节点,上一个节点就是tail指针指向的节点.
    (*tail).next = tmp;
    // 然后移动尾指针,让尾指针指向刚分配出来的新节点
    tail = tmp;
    // 分配第三个节点
    tmp = new st_girl({3,"elizabeth",nullptr});
    // 把上一个节点的next指针指向新节点,上一个节点就是tail指针指向的节点.
    (*tail).next = tmp;
    // 然后移动尾指针,让尾指针指向刚分配出来的新节点
    tail = tmp;
    
    // 现在链表中有三个节点,如果要遍历链表,沿着next指针往后找,直到next指针为空.
    tmp = head;
    while(tmp != nullptr) {
        // 将每个节点的编号,姓名和next指针的值显示出来.
        cout << "no = " << (*tmp).no << ", name = " << tmp -> name << ", tmp -> next = " << tmp -> next << endl;
        // 沿着next指向往后面找.
        tmp = (*tmp).next;
    }
    // 释放链表
    while(head != nullptr) {
        // 让临时节点指向头节点
        tmp = head;
        // 头节点后移
        head = head -> next;
        // 删除临时节点
        delete tmp;
    }
    
    
    
    cout << endl << endl << "==================linked-list==================" << endl;
};
