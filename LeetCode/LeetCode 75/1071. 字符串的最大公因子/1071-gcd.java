class Solution {
    public String gcdOfStrings(String str1, String str2) {
        int lg = gcd(str1.length(), str2.length());
        String ans = str1.substring(0, lg);
        if (isSs(str1, ans) && isSs(str2, ans)) {
            return ans;
        } else {
            return "";
        }
    }
    boolean isSs(String s, String ss) {
        if (ss.length() == 0) {
            return true;
        }
        if (s.length() % ss.length() != 0) {
            return false;
        }
        for (int i = 0; i < s.length(); i += ss.length()) {
            if (s.indexOf(ss, i) != i) {
                return false;
            }
        }
        return true;
    }
    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
}