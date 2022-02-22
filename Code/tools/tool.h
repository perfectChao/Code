//
//  tool.cpp
//  Code
//
//  Created by xuchao on 2022/2/21.
//

#include "stdc++.h"

using namespace std;

// convert vector to code
string print_code_arr(vector<int> arr) {
    string s = "{";
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        int x = arr[i];
        s += to_string(x);
        if (i != n - 1) s += ",";
    }
    s += "}";
    cout << s << endl;
    return s;
}

// convert str to code
string print_code_s(string s) {
    for (char& c : s) {
        if (c == '[') c = '{';
        else if (c == ']') c = '}';
    }
    cout << s << endl;
    return s;
}

// get primes
vector<int> get_primes(int n) {
    vector<int> arr;
    bool st[1000010];
    for (int i = 2; i <= n; i++) {
        int x = i;
        if (st[x]) continue;
        arr.push_back(x);
        for (int j = x + x; j <= n; j += x) {
            st[j] = true;
        }
    }
    print_code_arr(arr);
    return arr;
}
