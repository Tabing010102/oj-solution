class Solution {
    int[] h;
    public int maxArea(int[] height) {
        h = height;
        int l = 0, r = h.length - 1, ans = getArea(l, r);
        while (l < r) {
            ans = Math.max(ans, getArea(l, r));
            // move lower one won't skip bigger area
            if (h[l] > h[r]) {
                r--;
            } else {
                l++;
            }
        }
        return ans;
    }
    int getArea(int l, int r) {
        return (r - l) * Math.min(h[l], h[r]);
    }
}