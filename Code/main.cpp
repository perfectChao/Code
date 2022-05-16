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
    
    int curTime = 0;
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        priority_queue<int, vector<int>, greater<int>> s_pq;
        for (int i = 0; i < k; i++) s_pq.push(i);

        auto cmp = [&](auto p1, auto p2) {
            return p1.second > p2.second;
        };
        priority_queue<PII, vector<PII>, decltype(cmp)> pq(cmp);

        vector<int> ans;
        unordered_map<int, int> cnt;
        int mxCnt = 0;

        int pos = 0;
        int n = arrival.size();
        while (pos < n) {
            int now = arrival[pos], spend = load[pos];
            curTime = now;

            while (pq.size()) {
                auto t = pq.top();
                if (t.second - curTime <= 0) {
                    pq.pop();
                    s_pq.push(t.first);
                    continue;
                }
                break;
            }

            if (s_pq.size()) {
                int s_no = s_pq.top(); s_pq.pop();
                pq.push({s_no, now + spend});
                cnt[s_no]++;
                if (cnt[s_no] > mxCnt) {
                    mxCnt = cnt[s_no];
                    ans.clear();
                    ans.push_back(s_no);
                } else if (cnt[s_no] == mxCnt) {
                    ans.push_back(s_no);
                }
            }

            pos++;
        }

        return ans;
    }
};

int main() {
//    print_code_s("[[1,17],[4,5],[14,17],[5,11],[15,16]]");
    vector<int> v = {1,2,3,4,8,9,10};
    vector<int> v1 = {5,2,10,3,1,2,2};
    vector<vector<int>> vv = {{1,3},{6,9}};
    Solution s;
    vector<int> ans = s.busiestServers(3, v, v1);

    return 0;
}


