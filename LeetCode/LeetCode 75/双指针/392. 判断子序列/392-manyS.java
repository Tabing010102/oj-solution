import java.util.*;

class Solution {
    public boolean isSubsequence(String s, String t) {
        // d[i][j]: from t[i], next pos of char j (j" [0,25] <-> ['a','z'])
        int[][] d = new int[t.length()][26];
        for (int i = 0; i < t.length(); i++) {
            Arrays.fill(d[i], -1);
        }
        for (int i = 0; i < t.length(); i++) {
            int chIdx = t.charAt(i) - 'a';
            for (int j = 0; j <= i; j++) {
                if (d[j][chIdx] == -1) {
                    d[j][chIdx] = i;
                }
            }
        }
        // assume there are many String s
        // for one String s
        int tp = 0;
        for (int i = 0; i < s.length(); i++) {
            int chIdx = s.charAt(i) - 'a';
            if (tp >= t.length() || d[tp][chIdx] == -1) {
                return false;
            } else {
                tp = d[tp][chIdx];
            }
            tp++;
        }
        return true;
    }
}