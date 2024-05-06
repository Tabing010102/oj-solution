#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<char>>& d = board;
        bool vis[10];
        for (int i = 0; i < 9; i++) {
            // row
            memset(vis, 0, sizeof(vis));
            for (int j = 0; j < 9; j++) {
                if (d[i][j] != '.') {
                    if (vis[d[i][j] - '0']) { return false; }
                    vis[d[i][j] - '0'] = true;
                }
            }
            // col
            memset(vis, 0, sizeof(vis));
            for (int j = 0; j < 9; j++) {
                if (d[j][i] != '.') {
                    if (vis[d[j][i] - '0']) { return false; }
                    vis[d[j][i] - '0'] = true;
                }
            }
            // grid
            memset(vis, 0, sizeof(vis));
            int gi1 = i / 3, gi2 = i % 3;
            for (int j = 0; j < 9; j++) {
                int ji1 = j / 3, ji2 = j % 3;
                int x = gi1 * 3 + ji1, y = gi2 * 3 + ji2;
                if (d[x][y] != '.') {
                    if (vis[d[x][y] - '0']) { return false; }
                    vis[d[x][y] - '0'] = true;
                }
            }
        }
        return true;
    }
};

int main() {
    return 0;
}
