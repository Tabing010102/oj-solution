#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        int d1[26], d2[26];
        memset(d1, 0, sizeof(d1));
        memset(d2, 0, sizeof(d2));
        for (auto c : s) { d1[c - 'a']++; }
        for (auto c : t) { d2[c - 'a']++; }
        for (int i = 0; i < 26; i++) {
            if (d1[i] != d2[i]) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution s;
    auto ans = s.isAnagram("badc", "baba");
    cout << ans;
    return 0;
}
