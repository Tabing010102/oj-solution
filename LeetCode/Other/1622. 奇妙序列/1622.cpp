#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int MAXN = 1e5 + 10;
const int MOD = 1e9 + 7;

struct SEG {
	int addv[MAXN << 2], mulv[MAXN << 2];
	int curN, n;
	int oL, oR, oV;
	
	SEG() {
		memset(addv, 0, sizeof(addv));
		memset(mulv, 0, sizeof(mulv));
		n = 1e5;
		curN = 1;
	}
	
	void doAppend(int v) {
		oL = curN; oR = curN; oV = v;
		append(1, 1, n);
		curN++;
	}
	
	void pushdown(int o, int L, int R) {
		if (L == R) { return; }
		int lc = o * 2, rc = o * 2 + 1;
		int M = L + (R - L) / 2;
		if (mulv[o] != 0) {
			if (mulv[lc] != 0) { mulv[lc] = (int)(((LL)mulv[lc] * mulv[o]) % MOD); }
			else {
				if (L == M) { addv[lc] = (int)(((LL)addv[lc] * mulv[o]) % MOD); }
				else {
					if (addv[lc] != 0) { pushdown(lc, L, M); }
					mulv[lc] = mulv[o]; 
				}
			}
			if (mulv[rc] != 0) { mulv[rc] = (int)(((LL)mulv[rc] * mulv[o]) % MOD); }
			else {
				if (M + 1 == R) { addv[rc] = (int)(((LL)addv[rc] * mulv[o]) % MOD); }
				else {
					if (addv[lc] != 0) { pushdown(rc, M + 1, R); }
					mulv[rc] = mulv[o];
				}
			}
			mulv[o] = 0;
		}
		if (addv[o] != 0) {
			if (addv[lc] != 0) { addv[lc] = (int)(((LL)addv[lc] + addv[o]) % MOD); }
			else {
				if (mulv[lc] != 0) { pushdown(lc, L, M); }
				addv[lc] += addv[o];
			}
			if (addv[rc] != 0) { addv[rc] = (int)(((LL)addv[rc] + addv[o]) % MOD); }
			else {
				if (mulv[lc] != 0) { pushdown(rc, M + 1, R); }
				addv[rc] += addv[o];
			}
			addv[o] = 0;
		}
	}
	
	void append(int o, int L, int R) {
		if (L == R) {
			addv[o] = oV;
		} else {
			if (mulv[o] != 0 || addv[o] != 0) { pushdown(o, L, R); }
			int lc = o * 2, rc = o * 2 + 1;
			int M = L + (R - L) / 2;
			if (M >= oL) { append(lc, L, M); }
			else { append(rc, M + 1, R); }
		}
	}
	
	void add(int o, int L, int R) {
		if (L >= oL && R <= oR) {
			if (mulv[o] != 0) { pushdown(o, L, R); }
			addv[o] = (int)(((LL)addv[o] + oV) % MOD);
		} else {
			int lc = o * 2, rc = o * 2 + 1;
			int M = L + (R - L) / 2;
			pushdown(o, L, R);
			if (M >= oL) { add(lc, L, M); }
			if (M < oR) { add(rc, M + 1, R); }
		}
	}
	
	void doAddAll(int v) {
		if (curN <= 1) { return; }
		oL = 1; oR = curN - 1; oV = v;
		add(1, 1, n);
	}
	
	void mul(int o, int L, int R) {
		if (L >= oL && R <= oR) {
			if (addv[o] != 0) { pushdown(o, L, R); }
			if (L == R) { addv[o] = (int)(((LL)addv[o] * oV) % MOD); }
			else { mulv[o] = (int)(((LL)(mulv[o] == 0 ? 1 : mulv[o]) * oV) % MOD); }
		} else {
			int lc = o * 2, rc = o * 2 + 1;
			int M = L + (R - L) / 2;
			pushdown(o, L, R);
			if (M >= oL) { mul(lc, L, M); }
			if (M < oR) { mul(rc, M + 1, R); }
		}
	}
	
	void doMulAll(int v) {
		if (curN <= 1) { return; }
		oL = 1; oR = curN - 1; oV = v;
		mul(1, 1, n);
	}
	
	int get(int o, int L, int R) {
		if (L == R) { return addv[o]; }
		else {
			int lc = o * 2, rc = o * 2 + 1;
			int M = L + (R - L) / 2;
			int t;
			if (M >= oL) { t = get(lc, L, M); }
			else { t = get(rc, M + 1, R); }
			if (addv[o] != 0) { return (int)(((LL)t + addv[o]) % MOD); }
			else { return (int)(((LL)t * (mulv[o] == 0 ? 1 : mulv[o])) % MOD); }
		}
	}
	
	int getIdx(int idx) {
		if (curN <= idx + 1) { return -1; }
		oL = idx + 1; oR = idx + 1;
		return get(1, 1, n);
	}
};

class Fancy {
public:
	SEG seg;
	
    Fancy() {
		
    }
    
    void append(int val) {
		seg.doAppend(val);
    }
    
    void addAll(int inc) {
		seg.doAddAll(inc);
    }
    
    void multAll(int m) {
		seg.doMulAll(m);
    }
    
    int getIndex(int idx) {
		return seg.getIdx(idx);
    }
};

int main() {
	Fancy* obj = new Fancy();
	obj->append(2);
	obj->addAll(3);
	obj->append(7);
	obj->multAll(2);
	cout << obj->getIndex(0) << endl;
	obj->addAll(3);
	obj->append(10);
	obj->multAll(2);
	cout << obj->getIndex(0) << endl;
	cout << obj->getIndex(1) << endl;
	cout << obj->getIndex(2) << endl;
	return 0;
}
