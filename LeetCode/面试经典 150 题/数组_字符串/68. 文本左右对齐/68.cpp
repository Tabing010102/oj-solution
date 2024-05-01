#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int wn = words.size();
        int p = 0;
        vector<string> ans;
        while (p < wn) {
            int len = -1;
            int p0 = p;
            while (p < wn && len < maxWidth && len + words[p].size() + 1 <= maxWidth) {
                len += words[p].size() + 1;
                p++;
            }
            int cn = p - p0;
            string s = words[p0];
            if (cn == 1) {
                for (int i = words[p0].size(); i < maxWidth; i++) { s += ' '; }
            } else if (p == wn) {
                for (int i = p0 + 1, j = 0; i < p; i++, j++) {
                    s += ' ';
                    s += words[i];
                }
                for (int i = s.size(); i < maxWidth; i++) { s += ' '; }
            } else {
                int padsize = (maxWidth - len + (cn - 1)) / (cn - 1);
                int expadn = (maxWidth - len + (cn - 1)) - (cn - 1) * padsize;
                for (int i = p0 + 1, j = 0; i < p; i++, j++) {
                    for (int k = 0; k < padsize; k++) { s += ' '; }
                    if (j < expadn) { s += ' '; }
                    s += words[i];
                }
            }
            ans.push_back(s);
        }
        return ans;
    }
};

int main() {
//    vector<string> x = {"Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do"};
    vector<string> x = {"What","must","be","acknowledgment","shall","be"};
    Solution s;
    auto ans = s.fullJustify(x, 16);
    for (auto str : ans) { 
        printf("%s\n", str.c_str());   
    }
    return 0;
}
