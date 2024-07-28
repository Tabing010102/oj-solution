class Solution {
    public String mergeAlternately(String word1, String word2) {
        StringBuilder sb = new StringBuilder();
        int pos;
        for (pos = 0; pos < Math.min(word1.length(), word2.length()); pos++) {
            sb.append(word1.charAt(pos));
            sb.append(word2.charAt(pos));
        }
        if (word1.length() > word2.length()) {
            for (; pos < word1.length(); pos++) {
                sb.append(word1.charAt(pos));
            }
        } else if (word2.length() > word1.length()) {
            for (; pos < word2.length(); pos++) {
                sb.append(word2.charAt(pos));
            }
        }
        return sb.toString();
    }
}