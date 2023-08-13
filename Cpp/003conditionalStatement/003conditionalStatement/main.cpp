//
//  main.cpp
//  003conditionalStatement
//
//  Created by Lee ChenZe on 8/12/23.
//

#include <iostream>

using namespace std;

int main() {
    
    /** =========if else========= */
    bool appearance;
    int score;
    
    cout << "是否允许通过: " << endl;
    
    cin >> appearance;
    
    if(appearance) {
        cout << "允许通过,晋级下一轮!" << endl;
    }else{
        cout << "禁止通过,遗憾错过!" << endl;
    }
    cout << endl;
    
    
    
    
    
    /** =========switch========= */
    cout << "当前的分数: " << endl;
    cin >> score;
    switch (score) {
        case 1:
            cout << "优秀" << endl;
            return 0;
        case 2:
            cout << "及格" << endl;
            return 0;
        case 3:
            cout << "差劲" << endl;
            return 0;
    }
    
    
    
    
    
    
    
    
    
    cout << endl;
}
