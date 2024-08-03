import java.util.*;

class Solution {
    public int[] dailyTemperatures(int[] temperatures) {
        int d[] = temperatures;
        int ans[] = new int[d.length];
        Deque<Integer> s = new ArrayDeque<Integer>();
        for (int i = 0; i < d.length; i++) {
            if (s.isEmpty() || d[i] <= d[s.peek()]) {
                s.push(i);
            } else {
                while (!s.isEmpty() && d[i] > d[s.peek()]) {
                    int t = s.pop();
                    ans[t] = i - t;
                }
                s.push(i);
            }
        }
        while (!s.isEmpty()) {
            ans[s.pop()] = 0;
        }
        return ans;
    }
}