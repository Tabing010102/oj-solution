class Solution {
    public String reverseWords(String s) {
        String ws[] = s.trim().split("\\s+");
        StringBuilder sb = new StringBuilder(s.length());
        for (int i = ws.length - 1; i >= 0; i--) {
            sb.append(ws[i]);
            if (i > 0) {
                sb.append(" ");
            }
        }
        return sb.toString();
    }
}