#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<string, int> sm;
        string sd[26];
        int p = 0, pp = 0;
        int n = s.size();
        while (p < n && pp < pattern.size()) {
            int p0 = p;
            while (p < n && s[p] != ' ') { p++; }
            string cnt = s.substr(p0, p - p0);
            int ppi = pattern[pp] - 'a';
            if (sd[ppi] != "" && sd[ppi] != cnt) { return false; }
            if (sm.find(cnt) != sm.end() && sm[cnt] != ppi) { return false; }
            sd[ppi] = cnt;
            sm[cnt] = ppi;
            p++; pp++;
        }
        if (p != n + 1 || pp != pattern.size()) { return false; }
        else { return true; }
    }
};

int main() {
    Solution s;
//    auto ans = s.wordPattern("abba", "dog cat cat dog");
//    auto ans = s.wordPattern("abba", "dog cat cat fish");
    auto ans = s.wordPattern("aaaa", "dog cat cat dog");
    cout << ans;
    return 0;
}
