#include <iostream>
#include <cstring>
using namespace std;
typedef long long LL;
const LL maxn = 100000;
LL n, m, d[maxn+100];
struct SEG {
    LL n, sumv[4*maxn+100], addv[4*maxn+100];
    void upcurpinfo(LL o, LL L, LL R) {
        if(L < R) {
            LL lc=o*2, rc=o*2+1;
            sumv[o] = sumv[lc]+sumv[rc];
        } else sumv[o] = d[L];
        if(addv[o]) sumv[o] += addv[o]*(R-L+1);
    }
    void build(LL o, LL L, LL R) {
        if(L == R) sumv[o] = d[L];
        else {
            LL M = L + (R-L)/2;
            LL lc=o*2, rc=o*2+1;
            build(lc, L, M);
            build(rc, M+1, R);
        }
        upcurpinfo(o, L, R);
    }
    LL oL, oR, _sum;
    void qsum(LL o, LL L, LL R, LL _add=0) {
        if(L>=oL && R<=oR) {
            _sum += sumv[o]+_add*(R-L+1);
        } else {
            LL M = L + (R-L)/2;
            LL lc=o*2, rc=o*2+1;
            if(M >= oL) qsum(lc, L, M, _add+addv[o]);
            if(M < oR) qsum(rc, M+1, R, _add+addv[o]);
        }
    }
    LL _addv;
    void add(LL o, LL L, LL R) {
        if(L>=oL && R<=oR) {
            addv[o] += _addv;
        } else {
            LL M = L + (R-L)/2;
            LL lc=o*2, rc=o*2+1;
            if(M >= oL) add(lc, L, M);
            if(M < oR) add(rc, M+1, R);
        }
        upcurpinfo(o, L, R);
    }
    LL execute(LL opt, LL l, LL r, LL v=0) {
        if(opt == 1) {
            oL = l; oR = r; _sum = 0;
            qsum(1, 1, n);
            return _sum;
        } else if(opt == 2) {
            oL = l; oR = r; _addv = v;
            add(1, 1, n);
            return 0;
        } else {
            return 0;
        }
    }
    SEG(LL n) {
        memset(addv, 0, sizeof(addv));
        this->n = n;
        build(1, 1, n);
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(LL i = 1; i <= n; i++) cin >> d[i];
    SEG *D = new SEG(n);
    for(LL i = 1; i <= m; i++) {
        LL opt; cin >> opt;
        if(opt == 1) {
            LL l, r, k;
            cin >> l >> r >> k;
            D->execute(2, l ,r, k);
        } else if(opt == 2) {
            LL l, r;
            cin >> l >> r;
            LL ans = D->execute(1, l, r);
            cout << ans << endl;
        } else {
            cout << "GG" << endl;
        }
    }
    return 0;
}
