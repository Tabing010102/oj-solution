#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        vector<vector<int>>& d = matrix;
        int n = d.size();
        int m = n / 2;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                int x[4] = {i, j,         n - 1 - i, n - 1 - j};
                int y[4] = {j, n - 1 - i, n - 1 - j, i        };
                int l = d[x[3]][y[3]];
                for (int k = 0; k < 4; k++) {
                    int t = l;
                    l = d[x[k]][y[k]];
                    d[x[k]][y[k]] = t;
                }
            }
        }
        if (n % 2) {
            for (int i = 0; i < m; i++) {
                int x[4] = {i, m,         n - 1 - i, m};
                int y[4] = {m, n - i - 1, m,         i};
                int l = d[x[3]][y[3]];
                for (int k = 0; k < 4; k++) {
                    int t = l;
                    l = d[x[k]][y[k]];
                    d[x[k]][y[k]] = t;
                }
            }    
        }    
    }
};

int main() {
    vector<vector<int>> x;
    int t = 1;
    int m = 3, n = 3;
    for (int i = 0; i < m; i++) {
        vector<int> y;
        for (int j = 0; j < n; j++) { y.push_back(t++); }
        x.push_back(y);
    }
    Solution s;
    s.rotate(x);
    auto ans = x;
    for (auto a : ans) {
        for (auto b : a) { printf("%10d", b); }
        printf("\n");
    }
    return 0;
}
