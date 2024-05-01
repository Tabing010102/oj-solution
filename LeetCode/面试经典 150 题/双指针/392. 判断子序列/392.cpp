#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = t.size();
        int p = 0;
        for (auto it = s.begin(); it != s.end(); it++) {
            const char &c = *it;
            while (p < n && t[p] != c) { p++; }
            if (p >= n) { return false; }
            else { p++; }
        }
        return true;
    }
};

int main() {
    Solution s;
//    auto ans = s.isSubsequence("abc", "ahbgdc");
    auto ans = s.isSubsequence("axc", "ahbgdc");
    printf("%d", ans);
    return 0;
}
