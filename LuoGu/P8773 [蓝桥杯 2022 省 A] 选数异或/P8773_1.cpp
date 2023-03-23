#include <cstdio>
#include <cstring>

const int MAXN = 10000 + 10;

int n, m, x, A[MAXN];

struct SEG {
	int xorv[MAXN * 4];
	int n;
	SEG(int n) {
		this->n = n;
		memset(xorv, 0, sizeof(xorv));
		build(1, 1, n);
	}
	void build(int o, int L, int R) {
		if (L == R) xorv[o] = A[L];
		else {
			int lc = o*2, rc = o*2+1;
			int M = L + (R-L)/2;
			build(lc, L, M);
			build(rc, M+1, R);
			xorv[o] = xorv[lc] ^ xorv[rc];
		}
	}
	int oL, oR, _xorv;
	void qxor(int o, int L, int R) {
		if (oL <= L && oR >= R) {
			_xorv ^= xorv[o];
		} else {
			int lc = o*2, rc = o*2+1;
			int M = L + (R-L)/2;
			if (oL <= M) qxor(lc, L, M);
			if (oR > M) qxor(rc, M+1, R);
		}
	}
	int eqxor(int L, int R) {
		oL = L; oR = R;
		_xorv = 0;
		qxor(1, 1, n);
		return _xorv;
	}
};

int main() {
	scanf("%d%d%d", &n, &m, &x);
	for (int i = 1; i <= n; i++)
		scanf("%d", &A[i]);
	SEG *d = new SEG(n);
	for (int i = 0; i < m; i++) {
		int L, R;
		scanf("%d%d", &L, &R);
		int r = d->eqxor(L, R);
		printf("q%d-%d = %d\n", L, R, r);
		if (r == x) printf("yes\n");
		else printf("no\n");
	}
	return 0;
}
