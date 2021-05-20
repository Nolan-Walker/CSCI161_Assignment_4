//
//  main.cpp
//  Assignment4
//
//  Created by Nolan Caissie on 2017-03-14.
//  Copyright © 2017 Nolan Caissie. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "stack.h"
using namespace std;

int main(int argc, const char * argv[]) {
    
    stack brackets(1);
    ifstream in;
    in.open(argv[1]);
    
    if (in.fail()) {
        cout << "Could not open file" << endl;
        return 0;
    }
    char ch;
    while (!in.eof()){
        ch = in.get();
        if (ch == '(' || ch == '{' || ch == '[') {
            brackets.push(ch);
        }
        if (ch == ')' || ch == '}' || ch == ']'){
            if (brackets.isempty()){
                cout << "Error: unmatched closing bracket 1" << endl;
                return 0;
            }
            if (ch != brackets.top()) {
                cout << "Error: unmatched closing bracket 2" << endl;
                return 0;
            }
            brackets.pop();
        }
        if (brackets.isempty() == false){
            cout << "Error: unmatched closing bracket 3" << endl;
            return 0;
        }
        
    return 0;
    }
}
