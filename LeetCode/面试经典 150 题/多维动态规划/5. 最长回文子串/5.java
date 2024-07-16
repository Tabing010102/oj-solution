import java.util.Arrays;

class Solution {
    // f[i][j]: (i -> j) is palindrome
    public String longestPalindrome(String s) {
        boolean[][] f = new boolean[s.length()][s.length()];
        for (int i = 0; i < f.length; i++) {
            Arrays.fill(f[i], false);
        }
        int maxLen = 1;
        int stPos = 0, spPos = 0;
        char[] s2 = s.toCharArray();
        // for (int i = 0; i < f.length - 1; i++) {
        for (int i = f.length - 1 - 1; i >= 0; i--) {
            for (int j = i + 1; j < f.length; j++) {
                // if (s.charAt(i) == s.charAt(j) && 
                if (s2[i] == s2[j] && 
                    (j - i <= 2 || f[i + 1][j - 1] == true)) {
                        f[i][j] = true;
                        if (j - i + 1 > maxLen) {
                            maxLen = j - i + 1;
                            stPos = i;
                            spPos = j;
                        }
                    }
            }
        }
        return s.substring(stPos, spPos + 1);
    }
}