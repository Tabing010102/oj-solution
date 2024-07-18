import java.util.Arrays;

class Solution {
    // f[i][j] -> w1[i-1] -> w2[j-1]
    public int minDistance(String word1, String word2) {
        String w1 = word1, w2 = word2;
        int[][] f = new int[w1.length() + 1][w2.length() + 1];
        for (int i = 0; i <= w1.length(); i++) {
            Arrays.fill(f[i], 2000);
        }
        f[0][0] = 0;
        for (int j = 0; j <= w2.length(); j++) {
            for (int i = 0; i <= w1.length(); i++) {
                // delete
                if (i > 0) {
                    f[i][j] = Math.min(f[i][j], f[i - 1][j] + 1);
                }
                // none
                if (i > 0 && j > 0 && w1.charAt(i - 1) == w2.charAt(j - 1)) {
                    f[i][j] = Math.min(f[i][j], f[i - 1][j - 1]);
                } else {
                    // change
                    if (i > 0 && j > 0) {
                        f[i][j] = Math.min(f[i][j], f[i - 1][j - 1] + 1);
                    }
                    // add
                    if (j > 0) {
                        f[i][j] = Math.min(f[i][j], f[i][j - 1] + 1);
                    }
                }
            }
        }
        // for (int i = 0; i <= w1.length(); i++) {
        //     System.out.println();
        //     for (int j = 0; j <= w2.length(); j++) {
        //         System.out.print(Integer.valueOf(f[i][j]).toString() + " ");
        //     }
        // }
        return f[w1.length()][w2.length()];
    }
}