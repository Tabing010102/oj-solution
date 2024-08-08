import java.util.Arrays;

class Solution {
    final int MAXN = 1000 + 10;
    int[] f = new int[MAXN];
    int[] cost;
    int dp(int i) {
        if (i == 0 || i == 1) { return 0; }
        if (f[i] != -1) { return f[i]; }
        return f[i] = Math.min(dp(i - 1) + cost[i - 1], dp(i - 2) + cost[i - 2]);
    }
    public int minCostClimbingStairs(int[] cost) {
        this.cost = cost;
        Arrays.fill(f, -1);
        return dp(cost.length);
    }
}