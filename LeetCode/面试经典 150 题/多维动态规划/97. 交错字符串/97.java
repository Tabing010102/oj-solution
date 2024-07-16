import java.util.Arrays;

class Solution {
    // f[i][j] -> s1[0 -> i - 1] + s2[0 -> j - 1] ->? s3[0 -> i + j - 1]
    public boolean isInterleave(String s1, String s2, String s3) {
        if (s3.length() != s1.length() + s2.length()) {
            return false;
        }
        if (s1.length() == 0) {
            return s2.equals(s3);
        } else if (s2.length() == 0) {
            return s1.equals(s3);
        }
        boolean[][] f = new boolean[s1.length() + 1][s2.length() + 1];
        // for (int i = 0; i < f.length; i++) {
        //     Arrays.fill(f[i], false);
        // }
        f[0][0] = true;
        for (int i = 0; i <= s1.length(); i++) {
            for (int j = 0; j <= s2.length(); j++) {
                if (f[i][j] == true) {
                    continue;
                }
                if (i - 1 >= 0 && f[i - 1][j] == true && s3.charAt(i + j - 1) == s1.charAt(i - 1)) {
                    f[i][j] = true;
                }
                if (j - 1 >= 0 && f[i][j - 1] == true && s3.charAt(i + j - 1) == s2.charAt(j - 1)) {
                    f[i][j] = true;
                }
            }
        }
        // for (int i = 0; i < f.length; i++) {
        //     for (int j = 0; j < f[i].length; j++) {
        //         System.out.print((f[i][j] == true ? "1" : "0") + " ");
        //     }
        //     System.out.println();
        // }
        return f[s1.length()][s2.length()];
    }
}