#include "stdc++.h"
#include "tool.h"

#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define REP(i,n) for(int (i)=0;(i)<(int)(n);(i)++)

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

template <typename T> bool chkMax(T &x, T y) { return (y > x) ? x = y, 1 : 0; }
template <typename T> bool chkMin(T &x, T y) { return (y < x) ? x = y, 1 : 0; }

class Solution {
public:
    vector<int> presum;
    vector<int> arr;
    
    int cal(string& s, vector<int>& q) {
        if (arr.size() == 0) return 0;
        
        int lo = q[0], hi = q[1];
        int left = -1, right = -1;
        
        int l = 0, r = arr.size() - 1;
        while (l < r) {
            int mid = l + r >> 1;
            if (arr[mid] >= lo) r = mid;
            else l = mid + 1;
        }
        if (arr[r] >= lo) left = arr[r];
        else return 0;
        
        l = 0, r = arr.size() - 1;
        while (l < r) {
            int mid = l + r + 1 >> 1;
            if (arr[mid] <= hi) l = mid;
            else r = mid - 1;
        }
        if (arr[r] <= hi) right = arr[r];
        else return 0;
        
        if (left < right) return presum[right + 1] - presum[left];
        return 0;
    }
    
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int n = s.size();
        presum.resize(n + 1);
        for (int i = 1; i <= n; i++) {
            int x = s[i - 1] == '*' ? 1 : 0;
            if (x == 0) arr.pb(i - 1);
            presum[i] = presum[i - 1] + x;
        }
        
        vector<int> ans;
        for (auto& q : queries) {
            ans.pb(cal(s, q));
        }
        return ans;
    }
};

int main() {
//    print_code_s("[[1,17],[4,5],[14,17],[5,11],[15,16]]");
//    vector<int> v = {1,2,3};
    vector<vector<int>> vv = {{2,2}};
    Solution s;
    for (int x : s.platesBetweenCandles("***", vv)) {
        cout << x << endl;
    }

    return 0;
}


