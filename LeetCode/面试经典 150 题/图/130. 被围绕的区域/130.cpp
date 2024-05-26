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
    bool isAsideBond;
    bool vis[MAXN][MAXN];
    void dfs(vector<vector<char>> &G, int x, int y) {
        if (x < 0 || x >= G.size() || y < 0 || y >= G[0].size()) { return; }
        if (vis[x][y]) { return; }
        vis[x][y] = true;
        if (x == 0 || x == G.size() - 1 || y == 0 || y == G[0].size() - 1) { isAsideBond = true; }
        for (int i = 0; i < 4; i++) {
            int tx = x + DELTA[i][0], ty = y + DELTA[i][1];
            if (tx < 0 || tx >= G.size() || ty < 0 || ty >= G[0].size()) { continue; }
            if (G[tx][ty] != 'O' || vis[tx][ty]) { continue; }
            dfs(G, tx, ty);
        }
    }
    void dfs2(vector<vector<char>> &G, int x, int y) {
        if (x < 0 || x >= G.size() || y < 0 || y >= G[0].size()) { return; }
        if (!vis[x][y] || G[x][y] != 'O') { return; }
        G[x][y] = 'X';
        for (int i = 0; i < 4; i++) {
            int tx = x + DELTA[i][0], ty = y + DELTA[i][1];
            if (tx < 0 || tx >= G.size() || ty < 0 || ty >= G[0].size()) { continue; }
            if (!vis[tx][ty] || G[tx][ty] != 'O') { continue; }
            dfs2(G, tx, ty);
        }
    }
    void solve(vector<vector<char>>& board) {
        vector<vector<char>> &G = board;
        memset(vis, 0, sizeof(vis));
        for (int i = 0; i < G.size(); i++) {
            vector<char> &R = G[i];
            for (int j = 0; j < R.size(); j++) {
                if (R[j] == 'O' && !vis[i][j]) {
                    isAsideBond = false;
                    dfs(G, i, j);
                    if (!isAsideBond) { dfs2(G, i, j); }
                }
            }
        }
    }
};

int main() {
    Solution s;
    return 0;
}
