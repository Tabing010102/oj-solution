import java.util.*;

class Solution {
    public int maxOperations(int[] nums, int k) {
        int[] d = nums;
        Arrays.sort(d);
        int l = 0, r = d.length - 1;
        int ans = 0;
        while (l < r) {
            if (d[l] + d[r] == k) {
                ans++;
                l++; r--;
            } else if (d[l] + d[r] < k) {
                l++;
            } else {
                r--;
            }
        }
        return ans;
    }
}