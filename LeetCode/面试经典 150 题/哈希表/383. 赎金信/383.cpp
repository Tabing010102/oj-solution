#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int d[26];
        memset(d, 0, sizeof(d));
        for (auto c : magazine) { d[c - 'a']++; }
        for (auto c : ransomNote) {
            if (d[c - 'a'] <= 0) { return false; }
            d[c - 'a']--;
        }
        return true;
    }
};

int main() {
    Solution s;
    auto ans = s.canConstruct("aa", "aab");
    cout << ans;
    return 0;
}
