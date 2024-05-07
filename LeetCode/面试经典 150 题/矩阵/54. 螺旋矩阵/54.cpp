#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<vector<int>>& d = matrix;
        int m = d.size();
        int n = d[0].size();
        vector<int> ans;
        int i = 0, j = 0;
        while (1) {
            int ti = i, tj = j;
            for ( ; j < n - i - 1; j++) { ans.push_back(d[i][j]); }
            if ((i != 0 || j != 0) && i == ti && j == tj) { ans.push_back(d[i][j]); break; }
            ti = i, tj = j;
            for ( ; i < m - (n - j); i++) { ans.push_back(d[i][j]); }
            if (i == ti && j == tj) { ans.push_back(d[i][j]); break; }
            ti = i, tj = j;
            for ( ; j >= m - i; j--) { ans.push_back(d[i][j]); }
            if (i == ti && j == tj) { ans.push_back(d[i][j]); break; }
            ti = i, tj = j;
            for ( ; i > j + 1; i--) { ans.push_back(d[i][j]); }
            if (i == ti && j == tj) { ans.push_back(d[i][j]); break; }
        }
        return ans;
    }
};

int main() {
    vector<vector<int>> x;
    int t = 1;
    int m = 10, n = 2;
    for (int i = 0; i < m; i++) {
        vector<int> y;
        for (int j = 0; j < n; j++) { y.push_back(t++); }
        x.push_back(y);
    }
    Solution s;
    auto ans = s.spiralOrder(x);
    for (auto x : ans) { cout << x << " "; }
    return 0;
}
