import java.util.Deque;

class Solution {
    public int trap(int[] height) {
        int[] h = height;
        int ans = 0;
        Deque<Integer> s = new ArrayDeque<>();
        for (int i = 0; i < h.length; i++) {
            if (s.isEmpty() || h[i] <= h[s.peek()]) {
                if (!s.isEmpty() && h[i] == h[s.peek()]) { s.pop(); }
                s.push(i);
            } else {
                while (!s.isEmpty() && h[i] > h[s.peek()]) {
                    int tp = s.pop();
                    if (!s.isEmpty()) {
                        ans += (Math.min(h[i], h[s.peek()]) - h[tp]) * (i - s.peek() - 1);
                        // System.out.println("l=%d, m=%d, r=%d, add=%d".formatted(s.peek(), tp, i, (Math.min(h[i], h[s.peek()]) - h[tp]) * (i - s.peek())));
                    }
                }
                s.push(i);
            }
        }
        return ans;
    }
}