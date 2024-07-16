import java.util.Arrays;

class Solution {
    public List<List<Integer>> fourSum(int[] nums, int target) {
        List<List<Integer>> ans = new ArrayList<List<Integer>>();
        int[] d = nums;
        int n = d.length;
        if (n < 4) {
            return ans;
        }
        Arrays.sort(d);
        for (int p1 = 0; p1 < n - 3;) {
            for (int p2 = p1 + 1; p2 < n - 2;) {
                int rr = target - d[p1] - d[p2];
                int l = p2 + 1, r = n - 1;
                while (l < r) {
                    while (l < r && d[l] + d[r] < rr) { l++; }
                    while (l < r && d[l] + d[r] > rr) { r--; }
                    if (d[l] + d[r] == rr) {
                        ans.add(Arrays.asList(d[p1], d[p2], d[l], d[r]));
                        int d0 = d[l];
                        while (l < r && d[l] == d0) { l++; }
                        d0 = d[r];
                        while (l < r && d[r] == d0) { r--; }
                    }
                }

                int t2 = p2;
                while (t2 < n - 2 && d[t2] == d[p2]) { t2++; }
                p2 = t2;
            }
            int t1 = p1;
            while (t1 < n - 3 && d[t1] == d[p1]) { t1++; }
            p1 = t1;
        }
        return ans;
    }
}