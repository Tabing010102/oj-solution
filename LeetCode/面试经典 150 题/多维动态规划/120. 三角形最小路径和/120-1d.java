import java.util.*;

class Solution {
    public final int MAXN = 200 + 10;
    public final int INF = Integer.MAX_VALUE;
    public int minimumTotal(List<List<Integer>> triangle) {
        List<List<Integer>> d = triangle;
        int[] f = new int[MAXN];
        int[] fo = new int[MAXN];
        f[0] = d.get(0).get(0);
        for (int i = 0; i < d.size() - 1; i++) {
            System.arraycopy(f, 0, fo, 0, f.length);
            Arrays.fill(f, INF);
            for (int j = 0; j <= i; j++) {
                f[j] = Math.min(f[j], fo[j] + d.get(i + 1).get(j));
                f[j + 1] = Math.min(f[j + 1], fo[j] + d.get(i + 1).get(j + 1));
            }
        }
        int minVal = INF;
        for (int i = 0; i < d.get(d.size() - 1).size(); i++) {
            minVal = Math.min(f[i], minVal);
        }
        return minVal;
    }
}