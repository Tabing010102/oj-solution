class Solution {
    public boolean increasingTriplet(int[] nums) {
        int[] d = nums;
        int curMax = d[0];
        int cnt = 0;
        for (int i = 1; i < d.length && cnt < 2; i++) {
            if (d[i] > d[i - 1] && d[i] < curMax) {
                curMax = d[i];
            }
            if (d[i] > curMax) {
                cnt++;
                curMax = d[i];
            }
        }
        return cnt >= 2;
    }
}