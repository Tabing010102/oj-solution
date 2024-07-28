class Solution {
    public String gcdOfStrings(String str1, String str2) {
        String ans = new String(str1.length() > str2.length() ? str2 : str1);
        while (ans.length() > 0) {
            // System.out.println("ans = %s".formatted(ans));
            if (isSs(str1, ans) && isSs(str2, ans)) {
                break;
            } else {
                ans = ans.substring(0, ans.length() - 1);
            }
        }
        return ans;
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
}