//
// Created by Lee ChenZe on 10/8/24.
//

#include "iostream"

using namespace std;


class Hero1                        // 英雄基类
{
public:
    int viability;      // 生存能力。
    int attack;         // 攻击伤害。
    virtual void skill1() { cout << "英雄释放了一技能。\n"; }

    virtual void skill2() { cout << "英雄释放了二技能。\n"; }

    virtual void uskill() { cout << "英雄释放了大绝招。\n"; }
};

class XS1 : public Hero1       // 西施派生类
{
public:
    void skill1() { cout << "西施释放了一技能。\n"; }

    void skill2() { cout << "西施释放了二技能。\n"; }

    void uskill() { cout << "西施释放了大招。\n"; }

    void show() { cout << "我是天下第一美女。\n"; }
};

class HX1 : public Hero1       // 韩信派生类
{
public:
    void skill1() { cout << "韩信释放了一技能。\n"; }

    void skill2() { cout << "韩信释放了二技能。\n"; }

    void uskill() { cout << "韩信释放了大招。\n"; }
};

class LB1 : public Hero1       // 李白派生类
{
public:
    void skill1() { cout << "李白释放了一技能。\n"; }

    void skill2() { cout << "李白释放了二技能。\n"; }

    void uskill() { cout << "李白释放了大招。\n"; }
};

void run_phase_type_identification() {
    cout << endl << "========================run_phase_type_identification========================" << endl;


    // 根据用户选择的英雄，施展一技能、二技能和大招。
    int id = 0;     // 英雄的id。
    cout << "请输入英雄（1-西施；2-韩信；3-李白。）：";
    cin >> id;

    // 创建基类指针，让它指向派生类对象，用基类指针调用派生类的成员函数。
    Hero1 *ptr = nullptr;
    if (id == 1) {             // 1-西施
        ptr = new XS1;
    } else if (id == 2) {      // 2-韩信
        ptr = new HX1;
    } else if (id == 3) {      // 3-李白
        ptr = new LB1;
    }

    if (ptr != nullptr) {
        ptr->skill1();
        ptr->skill2();
        ptr->uskill();

        // 如果基类指针指向的对象是西施，那么就调用西施的show()函数。
        // if (id == 1) {
        //     XS1 *pxs = (XS1 *) ptr;        // C风格强制转换的方法，程序员必须保证目标类型正确。
        //     pxs->show();
        // }
        XS1 *xsptr = dynamic_cast<XS1 *>(ptr);         // 把基类指针转换为派生类。
        if (xsptr != nullptr) xsptr->show();              // 如果转换成功，调用派生类西施的非虚函数。

        delete ptr;
    }

    // 以下代码演示把基类引用转换为派生类引用时发生异常的情况。
    // HX1 hx;
    // Hero1 &rh = hx;
    // try {
    //     XS1 &rxs = dynamic_cast<XS1 &>(rh);
    // }
    // catch (bad_cast) {
    //     cout << "出现了bad_cast异常。\n";
    // }

    cout << endl << "========================run_phase_type_identification========================" << endl;
}