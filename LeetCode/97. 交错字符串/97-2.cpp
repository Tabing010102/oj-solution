#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100 + 5;
int m, n, o;
int f[MAXN][MAXN];

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        m = s1.size();
        n = s2.size();
        o = s3.size();
        if (o != m + n) { return false; }
        memset(f, 0, sizeof(f));
        f[0][0] = 1;
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                if (i < m && !f[i + 1][j] && s3[i + j] == s1[i]) { f[i + 1][j] = f[i][j]; }
                if (j < n && !f[i][j + 1] && s3[i + j] == s2[j]) { f[i][j + 1] = f[i][j]; }
            }
        }
//        for (int i = 0; i <= m; i++) {
//            for (int j = 0; j <= n; j++) { printf("%d ", f[i][j]); }
//            printf("\n");
//        }
        return f[m][n];
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
