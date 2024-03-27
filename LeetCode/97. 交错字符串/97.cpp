#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100 + 5;
int m, n, o;
int G[MAXN][MAXN];
int dpv[MAXN][MAXN];

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        m = s1.size();
        n = s2.size();
        o = s3.size();
        if (o != m + n) { return false; } 
    }
};

int main() {
    Solution s;
    auto ans = s.uniquePathsWithObstacles(x);
    cout << ans << endl;
    return 0;
}
