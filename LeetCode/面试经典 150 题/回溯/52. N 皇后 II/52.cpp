#include <bits/stdc++.h>

using namespace std;

const int MAXN = 9 + 2;

int d[MAXN];

class Solution {
public:
    int N, ans;
    void dfs(int cnt) {
        if (cnt == N) {
            ans++;
            return;
        }
        bool v2[MAXN];
        memset(v2, 0, sizeof(v2));
        for (int i = 0; i < cnt; i++) {
            v2[d[i]] = true;
            if (d[i] - (cnt - i) >= 0) { v2[d[i] - (cnt - i)] = true; }
            if (d[i] + (cnt - i) < N) { v2[d[i] + (cnt - i)] = true; }
        }
        for (int i = 0; i < N; i++) {
            if (!v2[i]) {
                d[cnt] = i;
                dfs(cnt + 1);
            }
        }
    }
    int totalNQueens(int n) {
        memset(d, 0, sizeof(d));
        N = n;
        ans = 0;
        dfs(0);
        return ans;
    }
};

int main() {
    Solution s;
    auto ans = s.totalNQueens(4);
    cout << ans << endl;
    return 0;
}
