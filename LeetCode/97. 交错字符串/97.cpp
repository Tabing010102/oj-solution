#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100 + 5;
string ds1, ds2, ds3;
int m, n, o;
int f[MAXN][MAXN];

class Solution {
public:
    bool dp(int i, int j) {
        if (i == 0 && j == 0) { return true; }
        else if (f[i][j] != -1) { return f[i][j]; }
        else { return f[i][j] = (i > 0 && (ds3[i + j - 1] == ds1[i - 1]) && dp(i - 1, j)) ||
                                (j > 0 && (ds3[i + j - 1] == ds2[j - 1]) && dp(i, j - 1)); }
    }
    bool isInterleave(string s1, string s2, string s3) {
        m = s1.size();
        n = s2.size();
        o = s3.size();
        if (o != m + n) { return false; }
        ds1 = s1;
        ds2 = s2;
        ds3 = s3;
        memset(f, -1, sizeof(f));
        return dp(m, n);
    }
};

int main() {
    Solution s;
    string s1 = "aabcc";
    string s2 = "dbbca";
    string s3 = "aadbbcbcac";
    auto ans = s.isInterleave(s1, s2, s3);
    cout << ans << endl;
    return 0;
}
