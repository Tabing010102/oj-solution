class Solution {
    public boolean canPlaceFlowers(int[] flowerbed, int n) {
        int[] d = flowerbed;
        int n0 = 0;
        for (int i = 0; i < d.length && n0 < n; ) {
            if (d[i] == 1) {
                i += 2;
            } else {
                if ((i == 0 || d[i - 1] == 0)
                    && (i == d.length - 1 || d[i + 1] == 0)) {
                    n0++;
                    i += 2;
                } else {
                    i++;
                }
            }
        }
        return n0 >= n;
    }
}