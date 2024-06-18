class Solution {
    public int findPeakElement(int[] nums) {
        int l = 0, r = nums.length - 1;
        // find the end of ascending seq
        while (l < r) {
            int m = l + (r - l) / 2;
            if (nums[m] > nums[m + 1]) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        return l;
    }
}