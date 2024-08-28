#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 32000 + 10;
const int MAXM = 60 + 3;

struct Wp {
	int v, p, q, s;
	Wp(int v, int p, int q, int s) : v(v), p(p), q(q), s(s) {}
	Wp() {}
	bool operator < (const Wp &rhs) const {
		if (q == rhs.q) { return s < rhs.s; }
		else if (q != 0 && rhs.q != 0) { return q < rhs.q; }
		else if (q != 0) { return q + 1 < rhs.s; }
		else { return s < rhs.q + 1; }
	}
};

int f[MAXM][MAXN];
int n, m;
Wp d[MAXM];
int ans = 0;

inline int max(const int &a, const int &b) { return a > b ? a : b; }

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		int v, p, q;
		scanf("%d%d%d", &v, &p, &q);
		d[i] = Wp(v, p, q, i);
	}
	sort(d + 1, d + 1 + m);
//	for (int i = 1; i <= m; i++) {
//		printf("Wp{v=%d, p=%d, q=%d, s=%d}\n", d[i].v, d[i].p, d[i].q, d[i].s);
//	}
	memset(f, 0, sizeof(f));
	for (int i = 1; i <= m; i++) {
		if (d[i].q == 0 && d[i].v * d[i].p <= n) {
			f[i][d[i].v] = d[i].v * d[i].p;
			ans = max(ans, f[i][d[i].v]);
		}
	}
	int last = -1;
	for (int i = 1; i <= m; i++) {
		for (int j = 0; j <= n - d[i].v; j++) {
			if (d[i].q != 0 && d[i].q != last) {
				f[i][j + d[i].v] = max(f[i][j + d[i].v], f[i - 1][j + d[i].v]);
//				f[i][j] = max(f[i][j], f[i - 1][j]);
			} else { f[i][j + d[i].v] = max(f[i - 1][j], f[i - 1][j] + d[i].v * d[i].p); }
			if (d[i].q == 0) { last = d[i].s; }
		}
	}
	for (int i = 0; i <= n; i++) { ans = max(ans, f[m][i]); }
	printf("%d\n", ans);
	return 0;
}
