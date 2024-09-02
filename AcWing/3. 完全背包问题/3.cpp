#include <cstdio>

using namespace std;

const int MAXN = 1000 + 10;

int N, V;
int v[MAXN], w[MAXN], f[MAXN];

inline int max(const int &a, const int &b) { return a > b ? a : b; }

int main() {
    scanf("%d%d", &N, &V);
    for (int i = 0; i < N; i++) { scanf("%d%d", &v[i], &w[i]); }
    for (int i = 0; i < N; i++) {
        for (int j = v[i]; j <= V; j++) {
            f[j] = max(f[j], f[j - v[i]] + w[i]);
        }
    }
    printf("%d\n", f[V]);
    return 0;
}
