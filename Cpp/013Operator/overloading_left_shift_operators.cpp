//
// Created by Lee ChenZe on 1/27/24.
//



#include <iostream>

using namespace std;

class CGirl0 {
    friend ostream &operator<<(ostream &cout, const CGirl0 &g);

    string name;
    int bust;
    int score;
public:
    CGirl0() {
        name = "Elizabeth";
        bust = 88;
        score = 30;
    }

    void show() {
        cout << "姓名：" << name << "，胸围：" << bust << "，评分：" << score << endl;
    }
};

ostream &operator<<(ostream &cout, const CGirl0 &g) {
    cout << "姓名：" << g.name << "，胸围：" << g.bust << "，评分：" << g.score << endl;
    return cout;
}

void overloading_left_shift_operators() {

    cout << endl;
    CGirl0 g;
    cout << g << endl;

    cout << endl << endl << "==================overloading_left_shift_operators==================" << endl;
}