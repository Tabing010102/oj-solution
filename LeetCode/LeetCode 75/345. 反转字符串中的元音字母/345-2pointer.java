import java.util.*;

class Solution {
    private static final List<Character> vowelChars = Arrays.asList('a', 'A', 'e', 'E', 'i', 'I', 'o', 'O', 'u', 'U');
    public String reverseVowels(String s) {
        char[] sc = s.toCharArray();
        int l = 0, r = sc.length - 1;
        char temp;
        while (l < r) {
            while (l < r && !isVowelChar(sc[l])) { l++; }
            while (l < r && !isVowelChar(sc[r])) { r--; }
            temp = sc[l];
            sc[l] = sc[r];
            sc[r] = temp;
            l++; r--;
        }
        return String.valueOf(sc);
    }
    boolean isVowelChar(char c) {
        return vowelChars.contains(c);
    }
}   