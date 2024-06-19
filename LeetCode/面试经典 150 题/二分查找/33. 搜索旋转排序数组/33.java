class Solution {
    int offset;
    int[] nums;
    int getActualIdx(int idx) {
        return (idx + offset + 1) % nums.length;
    }
    public int search(int[] nums, int target) {
        this.nums = nums;
        int l = 0, r = nums.length - 1;
        offset = -1;
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
        // System.out.format("offset = %d\n", offset);
        l = 0; r = nums.length - 1;
        while (l < r) {
            int m = l + (r - l) / 2;
            if (target == nums[getActualIdx(m)]) {
                return getActualIdx(m);
            } else if (target < nums[getActualIdx(m)]) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return target == nums[getActualIdx(l)] ? getActualIdx(l) : -1;
    }
}