import java.util.*;

class Solution {
    public List<List<String>> suggestedProducts(String[] products, String searchWord) {
        Trie trie = new Trie();
        for (String p : products) {
            trie.add(p);
        }
        return trie.search(searchWord);
    }
}

class Trie {
    class TN {
        public TN[] child;
        public boolean isLeaf;

        public TN() {}

        public void appendTN(char c, TN tn) {
            if (child == null) {
                child = new TN[26];
            }
            this.child[(int)c - 'a'] = tn;
        }
        public boolean getCh(char c) {
            if (this.child == null) {
                return false;
            } else {
                return this.child[(int)c - 'a'] != null;
            }
        }
        public boolean isLeaf() {
            return this.child == null || isLeaf;
        }
    }

    TN root = new TN();

    public void add(String s) {
        TN curTN = root;
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (!curTN.getCh(c)) {
                curTN.appendTN(c, new TN());
            }
            curTN = curTN.child[(int)c - 'a'];
        }
        curTN.isLeaf = true;
    }

    public List<List<String>> search(String s) {
        ArrayList<List<String>> ans = new ArrayList<>();
        TN curTN = root;
        String curStr = "";
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (curTN == null || curTN.child == null) { ans.add(new ArrayList<String>()); continue; }
            ArrayList<String> tans = new ArrayList<>();
            curTN = curTN.child[(int)c - 'a'];
            curStr += c;
            getLeaves(tans, curTN, curStr);
            ans.add(tans);
        }
        return ans;
    }

    void getLeaves(ArrayList<String> tans, TN tn, String s) {
        if (tn == null || tans.size() >= 3) { return; }
        if (tn.isLeaf()) { tans.add(s); }
        if (tn.child == null) { return; }
        for (int i = 0; i < 26 && tans.size() < 3; i++) {
            if (tn.child[i] != null) {
                getLeaves(tans, tn.child[i], s + (char)('a' + i));
            }
        }
    }
}