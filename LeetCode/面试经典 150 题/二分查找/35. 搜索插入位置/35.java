class Solution {
    public int searchInsert(int[] nums, int target) {
        int l = 0, r = nums.length;
        while (l < r - 1) {
            int m = l + (r - l) / 2;
            if (target <= nums[m]) {
                r = m;
            } else {
                l = m;
            }
        }
        if (nums[l] >= target) {
            l--;
        }
        return l + 1;
    }
}