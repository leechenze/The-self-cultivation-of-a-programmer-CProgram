//
// Created by Lee ChenZe on 1/21/24.
//

#include <iostream>

using namespace std;

class CGirl {
    friend CGirl &operator-(CGirl &cGirl, int score);

    friend CGirl &operator-(int score, CGirl &cGirl);

    friend CGirl &operator-(CGirl &cGirl0, CGirl &cGirl1);

private:
    int bust;
    int score;
public:
    string name;

    CGirl() {
        name = "Betty";
        bust = 87;
        score = 30;
    }

    void show() {
        cout << "name is : " << name << ", bust is : " << bust << ", score is : " << score << endl;
    }

    CGirl &operator+(int scoreVal) {
        score = score + scoreVal;
        return *this;
    }

};


CGirl &operator-(CGirl &cGirl, int score) {
    cGirl.score = cGirl.score - score;
    return cGirl;
}

CGirl &operator-(int score, CGirl &cGirl) {
    cGirl.score = cGirl.score - score;
    return cGirl;
}

CGirl &operator-(CGirl &cGirl0, CGirl &cGirl1) {
    cGirl0.score = cGirl0.score - cGirl1.score;
    return cGirl0;
}

void operator_basic() {

    cout << endl;
    CGirl cGirl;
    cGirl + 30;
    cGirl.show();
    // cGirl = cGirl - 20 - 10 - 5;
    // 等同于如下操作;
    // cGirl = operator-(operator-(operator-(cGirl, 20), 10), 5);
    // cGirl.show();
    cGirl = cGirl - 100 - cGirl;
    cGirl.show();

    cout << endl << endl << "==================operator_basic==================" << endl;
}