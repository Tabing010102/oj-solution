#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000 + 10;

class Solution {
public:
    string sa[MAXN];
    string convert(string s, int numRows) {
        if (numRows == 1) { return s; }
        for (int i = 0; i < numRows; i++) { sa[i] = ""; }
        int n = s.size();
        int p = 0;
        while (p < n) {
            for (int i = 0; i < numRows && p < n; i++) { sa[i] += s[p++]; }
            for (int i = numRows - 1 - 1; i > 0 && p < n; i--) { sa[i] += s[p++]; }
        }
        string ans;
        for (int i = 0; i < numRows; i++) { ans += sa[i]; }
        return ans;
    }
};

int main() {
    Solution s;
    auto ans = s.convert("PAYPALISHIRING", 3);
    printf("%s", ans.c_str());
    return 0;
}
