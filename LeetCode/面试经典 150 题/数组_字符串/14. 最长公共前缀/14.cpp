#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    inline int min(const int &a, const int &b) { return a < b ? a : b; }
    string longestCommonPrefix(vector<string>& strs) {
        string s = "";
        int n = 300;
        for (auto it = strs.begin(); it != strs.end(); it++) {
            n = min(n, it->size());
        }
        for (int i = 0; i < n; i++) {
            char c = 0;
            for (auto it = strs.begin(); it != strs.end(); it++) {
                string &sc = *it;
                if (c == 0) { c = sc[i]; }
                else if (sc[i] != c) { return s; }
                else { continue; }
            }
            s += c;
        }
        return s;
    }
};

int main() {
//    vector<string> x = {"flower","flow","flight"};
    vector<string> x = {"dog","racecar","car"};
    Solution s;
    auto ans = s.longestCommonPrefix(x);
    printf("%s", ans.c_str());
    return 0;
}
