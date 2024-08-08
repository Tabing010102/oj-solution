import java.util.Arrays;

class Solution {
    final int MAXN = 1000 + 10;
    // f[i][j] -> t1[i - 1], t2[j - 1]
    int[][] f = new int[MAXN][MAXN];
    public int longestCommonSubsequence(String text1, String text2) {
        for (int i = 0; i < text1.length(); i++) {
            Arrays.fill(f[i], 0);
        }
        for (int i = 0; i <= text1.length(); i++) {
            for (int j = 0; j <= text2.length(); j++) {
                if (i < text1.length()) { f[i + 1][j] = Math.max(f[i + 1][j], f[i][j]); }
                if (j < text2.length()) { f[i][j + 1] = Math.max(f[i][j + 1], f[i][j]); }
                if (i < text1.length() && j < text2.length()) {
                    f[i + 1][j + 1] = Math.max(f[i + 1][j + 1], f[i][j] + (text1.charAt(i) == text2.charAt(j) ? 1 : 0));
                }
            }
        }
        return f[text1.length()][text2.length()];
    }
}