class Solution {
    public int[] searchRange(int[] nums, int target) {
        if (nums.length == 0) {
            return new int[] {-1, -1};
        }
        int[] d = nums;
        int l = 0, r = d.length - 1;
        // left bound, [l, r]
        while (l < r) {
            int m = l + (r - l) / 2;
            if (target == d[m]) {
                r = m;
            } else if (target < d[m]) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        if (target != d[l]) {
            return new int[] {-1, -1};
        }
        int lBound = l;
        // right bound
        l = 0; r = d.length - 1;
        while (l < r) {
            int m = l + (r - l) / 2;
            if (target == d[m]) {
                if (l == m) {
                    if (m + 1 < d.length && target == d[m + 1]) {
                        l = m + 1;
                    } else {
                        r = l;
                    }
                } else {
                    l = m;
                }
            } else if (target < d[m]) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return new int[] {lBound, l};
    }
}