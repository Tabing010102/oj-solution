#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

const int MAXN = 100 + 10;
const int MAXX = 60000;

int n, dn;
int d[MAXN];
bool ip[MAXX + 10];
int ans = 0;
bool vis[MAXN];

void eS() {
    memset(ip, 0xff, sizeof(ip));
    ip[0] = false;
    ip[1] = false;
    for (int i = 2; i <= sqrt(MAXX) + 1; i++) {
        for (int j = 2; i * j <= MAXX; j++) {
            ip[i * j] = false;
        }
    }
}

inline bool isPrime(const int &a) { return ip[a]; }
inline int gcd(const int &a, const int &b) { return b == 0 ? a : gcd(b, a % b); }
inline int max(const int &a, const int &b) { return a > b ? a : b; }

void dfs(int dep, int last, int tans) {
    if (dep >= dn) { ans = max(ans, tans); return; }
    if (last == -1) {
        for (int i = 0; i < n; i++) if (!vis[i]) {
            vis[i] = true;
            dfs(dep + 1, d[i], tans);
            vis[i] = false;
        }
        dfs(dep + 1, -1, tans);
    } else {
        for (int i = 0; i < n; i++) if (!vis[i] && isPrime(last + d[i])) {
            vis[i] = true;
            dfs(dep + 1, -1, tans + 1);
            vis[i] = false;
        }
    }
}

void init1() {
    memset(vis, 0, sizeof(vis));
    dn = n;
    for (int i = 0; i < n; i++) {
        bool hp = false;
        for (int j = 0; j < n; j++) {
            if (i != j && isPrime(d[i] + d[j])) {
                hp = true;
                break;
            }
        }
        if (!hp) { vis[i] = true; dn--; }
    }
}

int main() {
    eS();
    scanf("%d", &n);
    for (int i = 0; i < n; i++) { scanf("%d", &d[i]); }
    init1();
    dfs(0, -1, 0);
    printf("%d\n", ans);
    return 0;
}
