#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100 + 10;
const int MAXL = 600 + 10;

int dp[MAXN][MAXN];
int d[MAXL][2];
int N;

class Solution {
public:
    int max(const int &a, const int &b) { return a > b ? a : b; }
    int findMaxForm(vector<string>& strs, int m, int n) {
        memset(dp, 0, sizeof(dp));
        memset(d, 0, sizeof(d));
        N = strs.size();
        for (int i = 0; i < N; i++) {
            for (auto it = strs[i].begin(); it != strs[i].end(); it++) {
                d[i][*it - '0']++;
            }
        }
        for (int i = 0; i < N; i++) {
            for (int l1 = m; l1 >= d[i][0]; l1--) {
                for (int l2 = n; l2 >= d[i][1]; l2--) {
                    dp[l1][l2] = max(dp[l1][l2], dp[l1 - d[i][0]][l2 - d[i][1]] + 1);
                }
            }
        }
        int ans = 0;
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                ans = max(ans, dp[i][j]);
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
//    vector<string> x = { "10", "0001", "111001", "1", "0" };
//    auto ans = s.findMaxForm(x, 5, 3);
    vector<string> x = { "1","0","1","0","1","0","1","0","1","0","1","0","1","0","1","0","1","0","1","0","1","0","1","0","1","0","1","0","1","0","1","0","1","0","1","0","1","0","1","0","1","0","1","0","1","0","1","0","1","0","1","0","1","0","1","0","1","0","1","0","1","0","1","0","1","0","1","0","1","0","1","0","1","0","1","0","1","0","1","0","1","0","1","0","1","0","1","0","1","0","1","0","1","0","1","0","1","0","1","0","1","0","1","0","1","0","1","0","1","0","1","0","1","0","1","0","1","0","1","0","1","0","1","0","1","0" };
    auto ans = s.findMaxForm(x, 30, 30);
    cout << ans << endl;
    return 0;
}
