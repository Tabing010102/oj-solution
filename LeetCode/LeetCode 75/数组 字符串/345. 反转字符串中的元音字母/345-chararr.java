import java.util.*;

class Solution {
    private static final List<Character> vowelChars = Arrays.asList('a', 'A', 'e', 'E', 'i', 'I', 'o', 'O', 'u', 'U');
    public String reverseVowels(String s) {
        char[] sc = s.toCharArray();
        char[] vcs = new char[sc.length];
        int vp = 0;
        for (int i = 0; i < sc.length; i++) {
            if (isVowelChar(sc[i])) {
                vcs[vp++] = sc[i];
            }
        }
        for (int i = 0; i < sc.length; i++) {
            if (isVowelChar(sc[i])) {
                sc[i] = vcs[--vp];
            }
        }
        return String.valueOf(sc);
    }
    boolean isVowelChar(char c) {
        return vowelChars.contains(c);
    }
}   