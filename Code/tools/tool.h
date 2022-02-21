//
//  tool.cpp
//  Code
//
//  Created by xuchao on 2022/2/21.
//

#include "stdc++.h"

using namespace std;

string arr2cpp(string s) {
    for (char& c : s) {
        if (c == '[') c = '{';
        else if (c == ']') c = '}';
    }
    return s;
}
