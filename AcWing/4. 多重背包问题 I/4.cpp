#include <cstdio>

using namespace std;

const int MAXN = 1000 + 10;

int N, V;
int v[MAXN], w[MAXN], s[MAXN], f[MAXN];

inline int max(const int &a, const int &b) { return a > b ? a : b; }

int main() {
    scanf("%d%d", &N, &V);
    for (int i = 0; i < N; i++) { scanf("%d%d%d", &v[i], &w[i], &s[i]); }
    for (int i = 0; i < N; i++) {
        for (int j = V; j >= v[i]; j--) {
            for (int k = 1; k <= s[i] && j - v[i] * k >= 0; k++) {
                f[j] = max(f[j], f[j - v[i] * k] + w[i] * k);
            }
        }
    }
    printf("%d\n", f[V]);
    return 0;
}
