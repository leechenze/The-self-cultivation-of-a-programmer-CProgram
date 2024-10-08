//
// Created by Lee ChenZe on 10/8/24.
//

#include <stdio.h>
#include <iostream>

using namespace std;


class Hero                        // 英雄基类
{
public:
    int viability;      // 生存能力。
    int attack;         // 攻击伤害。
    virtual void skill1() { cout << "英雄释放了一技能。\n"; }

    virtual void skill2() { cout << "英雄释放了二技能。\n"; }

    virtual void uskill() { cout << "英雄释放了大绝招。\n"; }
};

class XS : public Hero       // 西施派生类
{
public:
    void skill1() { cout << "西施释放了一技能。\n"; }

    void skill2() { cout << "西施释放了二技能。\n"; }

    void uskill() { cout << "西施释放了大招。\n"; }
};

class HX : public Hero       // 韩信派生类
{
public:
    void skill1() { cout << "韩信释放了一技能。\n"; }

    void skill2() { cout << "韩信释放了二技能。\n"; }

    void uskill() { cout << "韩信释放了大招。\n"; }
};

class LB : public Hero       // 李白派生类
{
public:
    void skill1() { cout << "李白释放了一技能。\n"; }

    void skill2() { cout << "李白释放了二技能。\n"; }

    void uskill() { cout << "李白释放了大招。\n"; }
};


void polymorphism_application_scenario() {
    cout << endl;

    // 根据用户选择的英雄，施展一技能、二技能和大招。
    int id = 0;     // 英雄的id。
    cout << "请输入英雄（1-西施；2-韩信；3-李白。）：";
    cin >> id;

    // 创建基类指针，让它指向派生类对象，用基类指针调用派生类的成员函数。
    Hero *ptr = nullptr;
    if (id == 1) {             // 1-西施
        ptr = new XS;
    } else if (id == 2) {      // 2-韩信
        ptr = new HX;
    } else if (id == 3) {      // 3-李白
        ptr = new LB;
    }

    if (ptr != nullptr) {
        ptr->skill1();
        ptr->skill2();
        ptr->uskill();
        delete ptr;
    }

    cout << "========================polymorphism_application_scenario========================" << endl;
}