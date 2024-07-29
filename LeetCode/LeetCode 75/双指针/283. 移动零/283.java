class Solution {
    public void moveZeroes(int[] nums) {
        int[] d = nums;
        int p = 0, p1 = 0;
        while (p < d.length) {
            while (p < d.length && d[p] != 0) {
                if (p != p1) {
                    d[p1] = d[p];
                }
                p++;
                p1++;
            }
            while (p < d.length && d[p] == 0) { p++; }
            if (p < d.length) {
                d[p1++] = d[p++];
            }
        }
        for (; p1 < d.length; p1++) {
            d[p1] = 0;
        }
    }
}