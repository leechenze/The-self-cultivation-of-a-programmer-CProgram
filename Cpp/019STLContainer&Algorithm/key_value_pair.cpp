//
// Created by Lee ChenZe on 5/28/25.
//
#include <iostream>;
#include <vector>;
#include <list>;

using namespace std;

void key_value_pair() {
    cout << endl << "========================key_value_pair========================" << endl;

    pair<int, string> p0;
    cout << "p0.first = " << p0.first << ", p0.second = " << p0.second << endl;

    pair<int, string> p1(1,"douglas");
    cout << "p1.first = " << p1.first << ", p1.second = " << p1.second << endl;


    cout << endl << "========================key_value_pair========================" << endl;
}
