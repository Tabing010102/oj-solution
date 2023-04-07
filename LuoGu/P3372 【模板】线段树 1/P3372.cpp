#include <cstdio>
#include <cstring>

const int MAXN = 100000+10;

int n, m;
int A[MAXN];

struct SEG {
	int n;
	int sumv[MAXN * 4], addv[MAXN * 4];
	int qL, qR, qaddv, _sumv;
	SEG(int n) {
		this->n = n;
		memset(addv, 0, sizeof(addv));
		build(1, 1, n);
	}
	void build(int o, int L, int R) {
		if (L == R) {
			sumv[o] = A[L];
		} else {
			int M = L + (R-L)/2;
			int lc = o*2, rc = o*2+1;
			build(lc, L, M);
			build(rc, M+1, R);
			sumv[o] = sumv[lc] + sumv[rc];
		}
	}
	void upcurpinfo(int o, int L, int R) {
		if (R > L) {
			int lc = o*2, rc = o*2+1;
			sumv[o] = sumv[lc] + sumv[rc];
		} else sumv[o] = A[L];
		sumv[o] += addv[o] * (R-L+1);
	}
	void add(int o, int L, int R) {
		if (L >= qL && R <= qR) {
			addv[o] += qaddv;
		} else {
			int M = L + (R-L)/2;
			int lc = o*2, rc = o*2+1;
			if (M >= qL) add(lc, L, M);
			if (M < qR) add(rc, M+1, R);
		}
		upcurpinfo(o, L, R);
	}
	void qsum(int o, int L, int R, int add=0) {
		if (L >= qL && R <= qR) {
			_sumv += sumv[o] + add * (R-L+1);
		} else {
			int M = L + (R-L)/2;
			int lc = o*2, rc = o*2+1;
			if (M >= qL) qsum(lc, L, M, add+addv[o]);
			if (M < qR) qsum(rc, M+1, R, add+addv[o]);
		}
	}
	void doAdd(int L, int R, int k) {
		qL = L;
		qR = R;
		qaddv = k;
		add(1, 1, n);
	}
	int doSum(int L, int R) {
		qL = L;
		qR = R;
		_sumv = 0;
		qsum(1, 1, n);
		return _sumv;
	}
};

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%d", &A[i]);
	SEG *d = new SEG(n);
	for (int i = 1; i <= m; i++) {
		int t, l, r, k;
		scanf("%d", &t);
		if (t == 1) {
			scanf("%d%d%d", &l, &r, &k);
			d->doAdd(l, r, k);
		} else if (t == 2) {
			scanf("%d%d", &l, &r);
			printf("%d\n", d->doSum(l, r));
		}
	}
	return 0;
}
