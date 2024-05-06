#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int tar[256 + 10], ttar = 0;
        memset(tar, 0, sizeof(tar));
        for (auto c : t) { tar[c]++; ttar++; }
        int vis[256 + 10], cnt = 0;
        memset(vis, 0, sizeof(vis));
        string ans = "";
        int l = 0, r = 0;
        while ((r == 0 || l < r) && r < n) {
            while (cnt < ttar && r < n) {
                int c = s[r];
                if (tar[c] > 0) {
                    if (vis[c] < tar[c]) { cnt++; }
                    vis[c]++;
                }
                r++;
            }
            if (cnt == ttar) {
                while (l < r && (tar[s[l]] == 0 || vis[s[l]] > tar[s[l]])) { vis[s[l++]]--; }
                if (ans == "" || r - l < ans.size()) { ans = s.substr(l, r - l); }
                vis[s[l++]]--; cnt--;
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    auto ans = s.minWindow("ADOBECODEBANC", "ABC");
    cout << ans << " ";
    return 0;
}
