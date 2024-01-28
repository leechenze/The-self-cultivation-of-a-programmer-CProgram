//
// Created by Lee ChenZe on 1/24/24.
//


//
// Created by Lee ChenZe on 1/21/24.
//

#include <iostream>

using namespace std;


class CGirl {
    string name;
    int appearance;
    int figure;
    int acting;
public:
    CGirl(string nameVal, int appearanceVal, int figureVal, int actingVal) {
        name = nameVal;
        appearance = appearanceVal;
        figure = figureVal;
        acting = actingVal;
    }

    bool operator==(const CGirl &cGirl) {
        if ((appearance + figure + acting) == (cGirl.appearance + cGirl.figure + cGirl.acting)) return true;
        return false;
    }

    bool operator>(const CGirl &cGirl) {
        if ((appearance + figure + acting) > (cGirl.appearance + cGirl.figure + cGirl.acting)) return true;
        return false;
    }

    bool operator<(const CGirl &cGirl) {
        if ((appearance + figure + acting) < (cGirl.appearance + cGirl.figure + cGirl.acting)) return true;
        return false;
    }

};

void overloading_relational_operators() {

    cout << endl;

    CGirl g0("Roosevelt", 7, 3, 3),
            g1("Clinton", 2, 3, 5);
    if (g0 == g1) {
        cout << "Clinton and Roosevelt have the same value" << endl;
    } else if (g0 > g1) {
        cout << "Roosevelt is more valuable than Clinton" << endl;
    } else if (g0 < g1) {
        cout << "Roosevelt is less valuable than Clinton" << endl;
    }

    cout << endl << endl << "==================overloading_relational_operators==================" << endl;
}