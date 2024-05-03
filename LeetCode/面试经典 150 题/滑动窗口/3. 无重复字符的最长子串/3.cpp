#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    inline int getIdx(const char &c) { return (int)c + 128; }
    inline int max(const int &a, const int &b) { return a > b ? a : b; }
    int lengthOfLongestSubstring(string s) {
        bool vis[256 + 10];
        int n = s.size();
        if (n == 0) { return 0; }
        int l = 0, r = 0;
        int ans = 1;
        memset(vis, 0, sizeof(vis));
        vis[getIdx(s[l])] = true;
        while (1) {
            while (r < n - 1 && !vis[getIdx(s[r + 1])]) { vis[getIdx(s[++r])] = true; }
            ans = max(ans, r - l + 1);
            if (r >= n - 1) { break; }
            while (l < r && getIdx(s[r + 1]) != getIdx(s[l])) { vis[getIdx(s[l++])] = false; }
            if (l == r) {
                const char &c = s[r];
                while (r < n - 1 && c == s[r + 1]) { r++; }
                memset(vis, 0, sizeof(vis));
                vis[getIdx(s[r])] = true;
                l = r;
            } else {
                vis[getIdx(s[l++])] = false;
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
//    auto ans = s.lengthOfLongestSubstring("abcabcbb");
//    auto ans = s.lengthOfLongestSubstring("bbbbb");
//    auto ans = s.lengthOfLongestSubstring("pwwkew");
//    auto ans = s.lengthOfLongestSubstring("abba");
    auto ans = s.lengthOfLongestSubstring("wobgrovw");
    cout << ans << endl;
    return 0;
}
