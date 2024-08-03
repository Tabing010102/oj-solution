import java.util.*;

class Solution {
    public int eraseOverlapIntervals(int[][] intervals) {
        int minl = Integer.MAX_VALUE, maxl = Integer.MIN_VALUE;
        for (int i = 0; i < intervals.length; i++) {
            minl = Math.min(minl, intervals[i][0]);
            maxl = Math.max(maxl, intervals[i][1]);
        }
        SEG seg = new SEG(maxl - minl);
        for (int i = 0; i < intervals.length; i++) {
            seg.doAdd(intervals[i][0] - minl + 1, intervals[i][1] - minl, 1);
        }
        return seg.doGetMaxv(1, maxl - minl) - 1;
    }
}
class SEG {
    private int n;
    private int[] maxv;
    private int[] addv;
    private int oL, oR;
    private int _addv;
    private int _maxv;

    public SEG(int n) {
        this.n = n;
        maxv = new int[n * 4];
        addv = new int[n * 4];
        Arrays.fill(maxv, 0);
        Arrays.fill(addv, 0);
    }

    public int doGetMaxv(int L, int R) {
        if (L > R) { return 0; }
        oL = L; oR = R; _maxv = 0;
        qmax(1, 1, n, 0);
        return _maxv;
    }

    public void doAdd(int L, int R, int v) {
        if (L > R) { return; }
        oL = L; oR = R; _addv = v;
        add(1, 1, n);
    }

    private void upcurpinfo(int o, int L, int R) {
        if (L < R) {
            maxv[o] = Math.max(maxv[o * 2], maxv[o * 2 + 1]);
        } else {
            maxv[o] = 0;
        }
        maxv[o] += addv[o];
    }

    private void add(int o, int L, int R) {
        if (L >= oL && R <= oR) {
            addv[o] += _addv;
        } else {
            int M = L + (R - L) / 2;
            if (M >= oL) { add(o * 2, L, M); }
            if (M < oR) { add(o * 2 + 1, M + 1, R); }
        }
        upcurpinfo(o, L, R);
    }

    private void qmax(int o, int L, int R, int _add) {
        if (L >= oL && R <= oR) {
            _maxv = Math.max(_maxv, maxv[o] + _add);
        } else {
            int M = L + (R - L) / 2;
            if (M >= oL) { qmax(o * 2, L, M, _add + addv[o]); }
            if (M < oR) { qmax(o * 2 + 1, M + 1, R, _add + addv[o]); }
        }
    }
}