class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        int[][] d = matrix;
        // [l, r)
        int l = 0, r = d.length;
        while (l < r - 1) {
            int m = l + (r - l) / 2;
            if (target <= d[m][0]) {
                r = m;
            } else {
                l = m;
            }
        }
        // System.out.println(l);
        if (target < d[l][0]) {
            return false;
        }
        int x = l;
        if (target > d[x][d[x].length - 1]) {
            x++;
        }
        if (x >= d.length) {
            return false;
        }
        // [l, r]
        l = 0; r = d[x].length - 1;
        while (l < r) {
            int m = l + (r - l) / 2;
            if (target == d[x][m]) {
                return true;
            } else if (target < d[x][m]) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        // System.out.println(l);
        return target == d[x][l];
    }
}