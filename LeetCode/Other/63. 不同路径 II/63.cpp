#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100 + 5;
int m, n;
int G[MAXN][MAXN];
int dpv[MAXN][MAXN];

class Solution {
public:
	int dp(int x, int y) {
        if (x < 0 || x >= m || y < 0 || y >= n) { return 0; }
        else if (G[x][y] == 1) { return 0; }
        else if (dpv[x][y] != -1) { return dpv[x][y]; }
        else { return dpv[x][y] = dp(x - 1, y) + dp(x, y - 1); }
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        memset(G, 0, sizeof(G));
        memset(dpv, -1, sizeof(dpv));
        m = obstacleGrid.size();
        n = obstacleGrid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                G[i][j] = obstacleGrid[i][j];
            }
        }
        if (G[0][0] == 1 || G[m][n] == 1) { return 0; }
        dpv[0][0] = 1;
        int ans = dp(m - 1, n - 1);
//        for (int i = 0; i < m; i++) {
//            for (int j = 0; j < n; j++) { printf("%d ", dpv[i][j]); }
//            printf("\n");
//        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> x1 = { 0,0,0 };
    vector<int> x2 = { 0,1,0 };
    vector<int> x3 = { 0,0,0 };
    vector<vector<int>> x = { x1,x2,x3 };
    auto ans = s.uniquePathsWithObstacles(x);
    cout << ans << endl;
    return 0;
}
