class Solution {
    public boolean isSubsequence(String s, String t) {
        int tp = 0;
        for (int sp = 0; sp < s.length(); sp++) {
            while (tp < t.length() && s.charAt(sp) != t.charAt(tp)) { tp++; }
            if (tp >= t.length()) {
                return false;
            }
            tp++;
        }
        return true;
    }
}