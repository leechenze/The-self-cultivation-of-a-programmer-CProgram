//
// Created by Lee ChenZe on 5/29/25.
//
#include <iostream>;
#include <vector>;
#include <list>;
#include <unordered_map>;
#include <cstdio>;
#include <queue>;

using namespace std;


class girl{
public:
    int m_bh;
    string m_name;
    girl(const int &bh, const string &name): m_bh(bh), m_name(name) {};
};


void queue_container() {
    cout << endl << "========================queue_container========================" << endl;

    // 创建队列
    // 以无力结构为链表
    queue<girl, list<girl>> q;
    // 物理结构为数组
    // queue<girl, deque<girl>> q;
    // queue<girl> q;

    q.push(girl(3, "douglas"));
    q.emplace(8, "hamilton");
    q.push(girl(5, "nixon"));
    q.push(girl(2, "hillary"));

    while(q.empty() == false) {
        cout << "编号 = " << q.front().m_bh << ", 姓名 = " << q.front().m_name << endl;
        q.pop();
    }

    cout << endl << "========================queue_container========================" << endl;
}
