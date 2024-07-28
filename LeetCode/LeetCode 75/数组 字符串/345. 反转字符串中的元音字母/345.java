import java.util.*;

class Solution {
    private static final List<Character> vowelChars = Arrays.asList('a', 'A', 'e', 'E', 'i', 'I', 'o', 'O', 'u', 'U');
    public String reverseVowels(String s) {
        char[] vcs = new char[s.length()];
        int vp = 0;
        for (int i = 0; i < s.length(); i++) {
            if (isVowelChar(s.charAt(i))) {
                vcs[vp++] = s.charAt(i);
            }
        }
        StringBuilder sb = new StringBuilder(s.length());
        for (int i = 0; i < s.length(); i++) {
            if (isVowelChar(s.charAt(i))) {
                sb.append(vcs[--vp]);
            } else {
                sb.append(s.charAt(i));
            }
        }
        return sb.toString();
    }
    boolean isVowelChar(char c) {
        return vowelChars.contains(c);
    }
}   