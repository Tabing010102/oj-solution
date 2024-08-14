// score 0

#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAXN = 1e5 + 10;

int T;
int n;
int x[MAXN], y[MAXN];
int r[MAXN];
int f[MAXN], fs[MAXN][2];

bool cmp(const int &a, const int &b) {
	if (x[a] == x[b]) { return y[a] < y[b]; }
	else { return x[a] < x[b]; }
}

inline int max(const int &a, const int &b) { return a > b ? a : b; }

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) { scanf("%d", &x[i]); }
		for (int i = 1; i <= n; i++) { scanf("%d", &y[i]); }
		x[0] = -1; y[0] = -1;
		for (int i = 0; i <= n; i++) { r[i] = i; }
		sort(r + 1, r + 1 + n, cmp);
		memset(f, 0, sizeof(f));
		memset(fs, -1, sizeof(fs));
//		for (int i = 1; i <= n; i++) {
//			f[i] = f[i - 1];
//			fs[i][0] = fs[i - 1][0]; fs[i][1] = fs[i - 1][1];
//			for (int j = 0; j < i; j++) {
//				if (f[j] + 1 > f[i] && x[r[i]] > fs[j][0] && y[r[i]] > fs[j][1]) {
//					f[i] = f[j] + 1;
//					fs[i][0] = x[r[i]]; fs[i][1] = y[r[i]];
//				}
//			}
//		}
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < i; j++) {
				if (f[j] + 1 > f[i] && x[r[i]] > x[r[j]] && y[r[i]] > y[r[j]]) {
					f[i] = f[j] + 1;
				}
			}
		}
//		for (int i = 0; i <= n; i++) { printf("%d ", f[i]); } printf("\n");
//		for (int i = 0; i <= n; i++) { printf("%d ", x[r[i]]); } printf("\n");
//		for (int i = 0; i <= n; i++) { printf("%d ", y[r[i]]); } printf("\n");
		printf("%d\n", f[n]);
	}
	return 0;
}
