#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool DEBUG = false;
    void setZeroes(vector<vector<int>>& matrix) {
        vector<vector<int>>& d = matrix;
        int m = d.size();
        int n = d[0].size();
        int cc0 = 0, cr0 = 0;
        for (int i = 0; i < m; i++) if (d[i][0] == 0) { cc0 = 1; }
        for (int i = 0; i < n; i++) if (d[0][i] == 0) { cr0 = 1; }
        // row
        for (int i = 1; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (d[i][j] == 0) { d[i][0] = 0; }
            }
        }
        if (DEBUG) {
            printf("12312312312313\n");
            for (auto a : d) {
                for (auto b : a) { printf("%10d", b); }
                printf("\n");
            }
        }
        // col
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (d[j][i] == 0) { d[0][i] = 0; }
            }
        }
        if (DEBUG) {
            printf("12312312312313\n");
            for (auto a : d) {
                for (auto b : a) { printf("%10d", b); }
                printf("\n");
            }
        }
        // row clr
        for (int i = 1; i < m; i++) {
            if (d[i][0] == 0) {
                for (int j = 0; j < n; j++) { d[i][j] = 0; }
            }
        }
        // col clr
        for (int i = 1; i < n; i++) {
            if (d[0][i] == 0) {
                for (int j = 0; j < m; j++) { d[j][i] = 0; }
            }
        }
        if (cc0) { for (int i = 0; i < m; i++) { d[i][0] = 0; } }
        if (cr0) { for (int i = 0; i < n; i++) { d[0][i] = 0; } }
    }
};

int main() {
    vector<vector<int>> x;
    int t = 1;
    int m = 3, n = 4;
    for (int i = 0; i < m; i++) {
        vector<int> y;
        for (int j = 0; j < n; j++) { y.push_back(t++); }
        x.push_back(y);
    }
    x[0][0] = 0;
    x[0][3] = 0;
    Solution s;
    s.setZeroes(x);
    auto ans = x;
    for (auto a : ans) {
        for (auto b : a) { printf("%10d", b); }
        printf("\n");
    }
    return 0;
}
