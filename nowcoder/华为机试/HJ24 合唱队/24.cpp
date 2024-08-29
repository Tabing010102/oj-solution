#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 3000 + 10;

int d[MAXN];
int f1[MAXN], f2[MAXN];
int n;

inline int max(const int &a, const int &b) { return a > b ? a : b; }

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) { scanf("%d", &d[i]); }
    for (int i = 1; i <= n; i++) { f1[i] = 1; f2[i] = 1; }
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            if (d[j] < d[i]) {
                f1[i] = max(f1[i], f1[j] + 1);
            }
        }
    }
    for (int i = n - 1; i >= 1; i--) {
        for (int j = n; j > i; j--) {
            if (d[j] < d[i]) {
                f2[i] = max(f2[i], f2[j] + 1);
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) if (f1[i] > 1 && f2[i] > 1) { ans = max(ans, f1[i] + f2[i] - 1); }
//    printf("f1: "); for (int i = 1; i <= n; i++) { printf("%d ", f1[i]); } printf("\n");
//    printf("f2: "); for (int i = 1; i <= n; i++) { printf("%d ", f2[i]); } printf("\n");
    printf("%d\n", n - ans);
    return 0;
}
