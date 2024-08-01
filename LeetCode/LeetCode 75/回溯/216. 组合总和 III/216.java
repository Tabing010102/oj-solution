import java.util.*;

class Solution {
    List<List<Integer>> ans;
    List<Integer> tans;
    int K, N;
    public List<List<Integer>> combinationSum3(int k, int n) {
        ans = new ArrayList<List<Integer>>();
        tans = new ArrayList<Integer>(Arrays.asList(new Integer[k]));
        K = k;
        N = n;

        dfs(0, 0, 0);
        return ans;
    }
    void dfs(int dep, int cur, int tot) {
        if (dep == K) {
            ans.add(new ArrayList<>(tans));
            return;
        }
        // not fully optim
        for (int i = cur + 1; i <= Math.min(9 - (K - dep) + 1, N - tot); i++) {
            if (dep == K - 1) {
                if (i == N - tot) {
                    tans.set(dep, i);
                    dfs(dep + 1, i, tot + i);
                }
            } else {
                tans.set(dep, i);
                dfs(dep + 1, i, tot + i);
            }
        }
    }
}