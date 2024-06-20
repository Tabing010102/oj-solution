class Solution {
    public int findMin(int[] nums) {
        int l = 0, r = nums.length - 1;
        int offset = -1;
        while (l < r && offset == -1) {
            int m = l + (r - l) / 2;
            if (nums[m] < nums[m + 1]) {
                if (nums[m] >= nums[0]) {
                    l = m + 1;
                } else {
                    r = m - 1;
                }
            } else {
                offset = m;
            }
        }
        if (nums[0] > nums[nums.length - 1] && offset == -1) {
            offset = l;
        }
        return nums[offset + 1];
    }
}