#include <bits/stdc++.h>

using namespace std;

const int MAXN = 300 + 10;
const int DELTA[4][2] = {
    {0, -1},
    {0, 1},
    {-1, 0},
    {1, 0}
};

class Solution {
public:
    bool vis[MAXN][MAXN];
    void dfs(vector<vector<char>> &G, int x, int y) {
        if (x < 0 || x >= G.size() || y < 0 || y >= G[0].size()) { return; }
        if (vis[x][y]) { return; }
        vis[x][y] = true;
        for (int i = 0; i < 4; i++) {
            int tx = x + DELTA[i][0], ty = y + DELTA[i][1];
            if (tx < 0 || tx >= G.size() || ty < 0 || ty >= G[0].size()) { continue; }
            if (G[tx][ty] != '1' || vis[tx][ty]) { continue; }
            dfs(G, tx, ty);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<char>> &G = grid;
        memset(vis, 0, sizeof(vis));
        int ans = 0;
        for (int i = 0; i < G.size(); i++) {
            vector<char> &R = G[i];
            for (int j = 0; j < R.size(); j++) {
                if (R[j] == '1' && !vis[i][j]) {
                    dfs(G, i, j);
                    ans++;
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    return 0;
}
