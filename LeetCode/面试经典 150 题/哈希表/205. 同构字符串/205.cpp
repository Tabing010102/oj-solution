#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int m1[256], m2[256];
        memset(m1, 0, sizeof(m1));
        memset(m2, 0, sizeof(m2));
        int n = s.size();
        for (int i = 0; i < n; i++) {
            int sc = s[i], tc = t[i];
            if (m1[sc] != 0 && m1[sc] != tc) { return false; }
            else if (m2[tc] != 0 && m2[tc] != sc) { return false; }
            else { m1[sc] = tc; m2[tc] = sc; }
        }
        return true;
    }
};

int main() {
    Solution s;
//    auto ans = s.isIsomorphic("egg", "add");
    auto ans = s.isIsomorphic("badc", "baba");
    cout << ans;
    return 0;
}
