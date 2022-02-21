#include "stdc++.h"

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

template <typename T> bool chkMax(T &x, T y) { return (y > x) ? x = y, 1 : 0; }
template <typename T> bool chkMin(T &x, T y) { return (y < x) ? x = y, 1 : 0; }

class Solution {
public:
    
    string arr2cpp(string s) {
        for (char& c : s) {
            if (c == '[') c = '{';
            else if (c == ']') c = '}';
        }
        return s;
    }

};

int main() {
    Solution s;
    return 0;
}


