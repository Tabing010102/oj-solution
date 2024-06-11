#include <bits/stdc++.h>

using namespace std;

const int DELTA[4][2] = {
    {-1, 0},
    {1, 0},
    {0, -1},
    {0, 1}
};
const int MAXN = 6 + 2;

class Solution {
public:
    bool ans;
    bool vis[MAXN][MAXN];
    int M, N;
    void dfs(const vector<vector<char>> &G, int x, int y, const string &word, int p) {
        if (ans || p == word.size()) {
            ans = true;
        } else {
            printf("dfs x=%d, y=%d, g=%c, p=%d, w[p]=%c\n", x, y, G[x][y], p, word[p]);
            vis[x][y] = true;
            const char &c = word[p];
            for (int i = 0; i < 4; i++) {
                int tx = x + DELTA[i][0], ty = y + DELTA[i][1];
                if (tx < 0 || tx >= M || ty < 0 || ty >= N) { continue; }
                if (vis[tx][ty]) { continue; }
                if (G[tx][ty] != c) { continue; }
                dfs(G, tx, ty, word, p + 1);
            }
            vis[x][y] = false;
        }
    }
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<char>>& G = board;
        M = G.size();
        N = G[0].size();
        ans = false;
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (!ans && G[i][j] == word[0]) {
                    memset(vis, 0, sizeof(vis));
                    vis[i][j] = true;
                    dfs(G, i, j, word, 1);
                }
            }
        }
        return ans;
    }
};

int main() {
    vector<vector<char>> x = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'E', 'S'},
        {'A', 'D', 'E', 'E'}
    };
    Solution s;
    auto ans = s.exist(x, "ABCESEEEFS");
    cout << ans << endl;
    return 0;
}
