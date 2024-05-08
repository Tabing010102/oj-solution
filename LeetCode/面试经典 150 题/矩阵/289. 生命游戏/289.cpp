#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    const int DX[3] = {-1, 0, 1};
    const int DY[3] = {-1, 0, 1};
    bool DEBUG = false;
    int m, n;
    int getCellAlive(vector<vector<int>>& d, int x, int y) {
        int c = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                int nx = x + DX[i], ny = y + DY[j];
                if (nx < 0 || nx >= m || ny < 0 || ny >= n) { continue; }
                if (nx == x && ny == y) { continue; }
                if ((d[nx][ny] & 1) == 1) { c++; }
            }
        }
        return c;
    }
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>>& d = board;
        m = d.size();
        n = d[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int cAlive = getCellAlive(d, i, j);
                int ca = ((d[i][j] & 1) == 1) ? 1 : 0;
                if ((!ca && cAlive == 3)
                    || (ca && cAlive >= 2 && cAlive <= 3)) {
                        if (DEBUG) { printf("d[%d][%d]: %d ", i, j, d[i][j]); }
                        d[i][j] |= 2;
                        if (DEBUG) { printf("-> %d\n", d[i][j]); }
                    }
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                d[i][j] &= 2;
                d[i][j] >>= 1;
            }
        }
    }
};

int main() {
    vector<vector<int>> x;
    int t = 1;
    int m = 2, n = 2;
    for (int i = 0; i < m; i++) {
        vector<int> y;
        for (int j = 0; j < n; j++) { y.push_back(1); }
        x.push_back(y);
    }
    x[1][1] = 0;
    Solution s;
    s.gameOfLife(x);
    auto ans = x;
    for (auto a : ans) {
        for (auto b : a) { printf("%2d", b); }
        printf("\n");
    }
    return 0;
}
