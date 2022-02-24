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

int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

class Solution {
public:
    int L = -1, R = 1;
    int m, n;
    
    int dfs(int x, int y, vector<vector<int>>& g) {
        int nx = x + 1;
        int ny = g[x][y] == L ? y - 1 : y + 1;
        if (ny < 0 || ny >= n) return -1;
        if (g[x][y] != g[x][ny]) return -1;
        if (x == m - 1) return y;
        return dfs(nx, ny, g);
    }
    
    vector<int> findBall(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        vector<int> ans;
        for (int i = 0, j = 0; j < n; j++) {
            ans.push_back(dfs(i, j, grid));
        }
        return ans;
    }
};

int main() {
    print_code_s("[[1,1,1,1,1,1],[-1,-1,-1,-1,-1,-1],[1,1,1,1,1,1],[-1,-1,-1,-1,-1,-1]");
    vector<vector<int>> vv = {{1,1,1,1,1,1},{-1,-1,-1,-1,-1,-1},{1,1,1,1,1,1},{-1,-1,-1,-1,-1,-1}};
    Solution s;
    print_code_arr(s.findBall(vv));
    return 0;
}


