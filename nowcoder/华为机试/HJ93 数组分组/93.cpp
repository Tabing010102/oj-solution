#include <cstdio>
#include <algorithm>
#include <cstdlib>

using namespace std;

const int MAXN = 50 + 5;

int n, d[MAXN], df[MAXN], m, p[MAXN];
int d1, d2, tar;
bool ans = false;

void dfs(int idx, int cnt) {
    if (ans) { return; }
    if (cnt == tar) { ans = true; return; }
    if (idx >= m) { return; }
//    if (cnt > p[idx]) { return; }
    dfs(idx + 1, cnt + df[idx]);
    dfs(idx + 1, cnt);
}

int main() {
    scanf("%d", &n);
    int s = 0;
    for (int i = 0; i < n; i++) { scanf("%d", &d[i]); s += d[i]; }
    if (s % 2 != 0) { printf("false\n"); exit(0); }
    for (int i = 0; i < n; i++) {
        if (d[i] % 5 == 0) { d1 += d[i]; }
        else if (d[i] % 3 == 0) { d2 += d[i]; }
        else { df[m++] = d[i]; }
    }
    sort(df, df + m);
    // cnt = (s - 2*d1) / 2
    tar = (s - 2 *d1) / 2;
    p[m - 1] = df[m - 1];
    for (int i = m - 2; i >= 0; i--) { p[i] = p[i + 1] + df[i]; }
    dfs(0, 0);
    printf("%s\n", ans ? "true" : "false");
    return 0;
}
