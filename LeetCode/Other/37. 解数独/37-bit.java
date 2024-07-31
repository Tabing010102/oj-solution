import java.util.Arrays;

class Solution {
    boolean iv[][] = new boolean[9][9];
    char oG[][];
    int G[][] = new int[9][9];
    // 0 row 1 col 2 block
    int vis[][] = new int[3][9];
    boolean done;
    public void solveSudoku(char[][] board) {
        // init
        oG = board;
        for (int i = 0; i < 3; i++) {
                Arrays.fill(vis[i], 0);
        }
        int t;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (oG[i][j] == '.') {
                    iv[i][j] = false;
                    G[i][j] = -1;
                } else {
                    t = (int)oG[i][j] - '0';
                    iv[i][j] = true;
                    G[i][j] = t;
                    // vis[0][i][t] = true;
                    // vis[1][j][t] = true;
                    // vis[2][gB(i, j)][t] = true;
                    setVis(0, i, t, true);
                    setVis(1, j, t, true);
                    setVis(2, gB(i, j), t, true);
                }
            }
        }
        done = false;
        // work
        dfs(0);
    }
    int gB(int i, int j) {
        return (i / 3) * 3 + (j / 3);
    }
    void setVis(int scope, int x, int offset, boolean value) {
        if (value) {
            vis[scope][x] |= 0x1 << offset;
        } else {
            vis[scope][x] &= 0xffffffff - (0x1 << offset);
        }
    }
    boolean getVis(int scope, int x, int offset) {
        return (vis[scope][x] & (0x1 << offset)) > 0;
    }
    void dfs(int idx) {
        if (idx == 81) { saveAns(); done = true; return; }
        if (done) { return; }
        int i = idx / 9, j = idx % 9;
        if (iv[i][j] == true) { dfs(idx + 1); return; }
        for (int t = 1; t <= 9 && !done; t++) {
            // if (vis[0][i][t] || vis[1][j][t] || vis[2][gB(i, j)][t]) { continue; }
            // else {
            //     vis[0][i][t] = vis[1][j][t] = vis[2][gB(i, j)][t] = true;
            //     G[i][j] = t;
            //     dfs(idx + 1);
            //     vis[0][i][t] = vis[1][j][t] = vis[2][gB(i, j)][t] = false;
            // }
            if (getVis(0, i, t) || getVis(1, j, t) || getVis(2, gB(i, j), t)) { continue; }
            else {
                setVis(0, i, t, true);
                setVis(1, j, t, true);
                setVis(2, gB(i, j), t, true);
                G[i][j] = t;
                dfs(idx + 1);
                setVis(0, i, t, false);
                setVis(1, j, t, false);
                setVis(2, gB(i, j), t, false);
            }
        }
    }
    void saveAns() {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (!iv[i][j]) {
                    oG[i][j] = (char)(G[i][j] + '0');
                }
            }
        }
    }
}