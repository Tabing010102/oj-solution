#include <bits/stdc++.h>

using namespace std;

const int MAXN = 20 + 5;

int n;
int d[MAXN * MAXN + 10];

class Solution {
public:
    int getG(vector<vector<int>>& G, int idx) {
        int x = (n - 1) - ((idx - 1) / n);
        int y = (idx - 1) % n;
        if ((n - 1 - x) % 2 == 1) { y = (n - 1) - y; }
        return G[x][y];
    }
    int snakesAndLadders(vector<vector<int>>& board) {
        vector<vector<int>>& G = board;
        n = G.size();
        memset(d, -1, sizeof(d));
        queue<int> q;
        d[1] = 0;
        q.push(1);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int i = 1; i <= 6 && i + u <= n * n; i++) {
                int ni = u + i;
                int nix = getG(G, ni);
                if (ni == 5) {
//                    printf("ni  u = %d, i = %d, d[u] = %d, ni = 35\n", u, i, d[u]); 
                    getG(G, ni);
                }
//                if (nix == 5) { printf("nix u = %d, i = %d, d[u] = %d, ni = 35\n", u, i, d[u]); }
                if (nix == -1 && (d[ni] == -1 || d[ni] > d[u] + 1)) {
//                    if (ni == 5) { printf("ni  u = %d, i = %d, d[u] = %d, nix = %d\n", u, i, d[u], nix); }
                    d[ni] = d[u] + 1;
                    q.push(ni);
                }
                if (nix != -1 && (d[nix] == -1 || d[nix] > d[u] + 1)) {
//                    if (nix == 5) { printf("nix u = %d, i = %d, d[u] = %d\n", u, i, d[u]); }
                    d[nix] = d[u] + 1;
                    q.push(nix);
                }
            }
        }
//        for (int i = 0; i < n; i++) {
//            for (int j = 0; j < n; j++) {
//                int x = n - 1 - i;
//                int y = j;
//                if (x % 2) { y = n - 1 - y; }
//                int idx = x * n + y + 1;
//                printf("%d ", d[idx]);
//            }
//            printf("\n");
//        }
        return d[n * n];
    }
};

int main() {
//    vector<vector<int>> x = {
//        {-1,-1,-1,-1,-1,-1},
//        {-1,-1,-1,-1,-1,-1},
//        {-1,-1,-1,-1,-1,-1},
//        {-1,35,-1,-1,13,-1},
//        {-1,-1,-1,-1,-1,-1},
//        {-1,15,-1,-1,-1,-1}
//    };
//    vector<vector<int>> x = {
//        {1,1,-1},
//        {1,1,1},
//        {-1,1,1}
//    };
    vector<vector<int>> x = {
        {-1,-1,19,10,-1},
        {2,-1,-1,6,-1},
        {-1,17,-1,19,-1},
        {25,-1,20,-1,-1},
        {-1,-1,-1,-1,15}
    };
    Solution s;
    s.snakesAndLadders(x);
    return 0;
}
