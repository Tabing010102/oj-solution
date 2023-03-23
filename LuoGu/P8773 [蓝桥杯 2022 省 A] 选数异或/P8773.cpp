#include <cstdio>
#include <cstring>

const int MAXN = 10000 + 10;

int n, m, x, A[MAXN];
int d[MAXN];

int main() {
	scanf("%d%d%d", &n, &m, &x);
	for (int i = 1; i <= n; i++)
		scanf("%d", &A[i]);
	d[0] = 0; d[1] = 0;
	for (int i = 2; i <= n; i++) {
		int t = 0;
		for (int j = 1; j < i; j++)
			if ((A[i] ^ A[j]) == x)
				t++;
		d[i] = d[i-1] + t;
	}
	for (int i = 0; i < m; i++) {
		int L, R;
		scanf("%d%d", &L, &R);
		if (d[R] - d[L] > 0) printf("yes\n");
		else printf("no\n");
	}
	return 0;
}
