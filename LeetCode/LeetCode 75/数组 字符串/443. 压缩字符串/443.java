class Solution {
    public int compress(char[] chars) {
        int pc = 0, pa = 0;
        while (pc < chars.length) {
            int pc0 = pc;
            char ch = chars[pc++];
            while (pc < chars.length && chars[pc] == ch) { pc++; }
            if (pc - pc0 > 1) {
                chars[pa++] = ch;
                // insert num
                int n = pc - pc0;
                int ds = 0;
                while (n > 0) {
                    n /= 10;
                    ds++;
                }
                int ds0 = ds;
                n = pc - pc0;
                for (int i = ds - 1, p = pa + ds - 1; i >= 0; i--, p--) {
                    chars[p] = (char)((int)(n % 10) + '0');
                    n /= 10;
                }
                pa += ds0;
            } else {
                chars[pa++] = ch;
            }
        }
        return pa;
    }
}