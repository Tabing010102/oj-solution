#include <cstdio>
#include <cstring>

using namespace std;

int G[9][9];
bool vis[3][9][10];
int ansG[9][9];
bool found = false;

inline int gx(const int &p) { return p / 9; }
inline int gy(const int &p) { return p % 9; }
inline int gb(const int &x, const int &y) { return (x / 3) * 3 + (y / 3); }
inline int gb(const int &p) { return gb(gx(p), gy(p)); }

void setVis(const int &x, const int &y, const int &val, const bool &bval) {
    vis[0][x][val] = bval;
    vis[1][y][val] = bval;
    vis[2][gb(x, y)][val] = bval;
}
void setp(const int &p, const int &val) { setVis(gx(p), gy(p), val, true); }
void unsetp(const int &p, const int &val) { setVis(gx(p), gy(p), val, false); }
bool exists(const int &p, const int &val) {
    return vis[0][gx(p)][val]
        || vis[1][gy(p)][val]
        || vis[2][gb(p)][val];
}

void dfs(int p) {
    if (found) { return; }
    if (p == 81) {
        memcpy(ansG, G, sizeof(G));
        found = true;
        return;
    }
    if (G[gx(p)][gy(p)] != 0) { dfs(p + 1); }
    else {
        for (int i = 1; i <= 9; i++) if (!exists(p, i)) {
            G[gx(p)][gy(p)] = i;
            setp(p, i);
            dfs(p + 1);
            unsetp(p, i);
            G[gx(p)][gy(p)] = 0;
        }
    }
}

int main() {
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            scanf("%d", &G[i][j]);
            if (G[i][j] != 0) { setVis(i, j, G[i][j], true); }
        }
    }
    dfs(0);
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            printf("%d ", ansG[i][j]);
        }
        printf("\n");
    }
    return 0;
}
