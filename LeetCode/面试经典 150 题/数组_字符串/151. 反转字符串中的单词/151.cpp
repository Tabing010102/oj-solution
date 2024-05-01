#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    inline void swap(char &a, char &b) { char t = a; a = b; b = t; }
    void reverseStr(string &s, int begin, int end) {
        while (begin < end) { swap(s[begin++], s[end--]); }
    }
    string reverseWords(string s) {
        int l = 0, r = 0;
        int n = s.size();
        while (r < n && s[r] == ' ') { r++; }
        while (r < n) {
            while (r < n && s[r] != ' ') { s[l++] = s[r++]; }
            while (r < n && s[r] == ' ') { r++; }
            if (r < n) s[l++] = ' ';
        }
        s.resize(l);
        reverseStr(s, 0, l - 1);
        int p = 0;
        while (p < l) {
            int p0 = p;
            while (p < l && s[p] != ' ') { p++; }
            reverseStr(s, p0, p - 1);
            while (p < l && s[p] == ' ') { p++; }
        }
        return s;
    }
};

int main() {
//    string str = "  hello world  ";
    string str = "a good   example";
    Solution s;
    auto ans = s.reverseWords(str);
    printf("%s", ans.c_str());
    return 0;
}
