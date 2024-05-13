#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    static bool cmp(const vector<int> &a, const vector<int> &b) {
        if (a[0] != b[0]) { return a[0] < b[0]; }
        else { return a[1] < b[1]; }
    }
    static inline int max(const int &a, const int &b) { return a > b ? a : b; }
    static inline int min(const int &a, const int &b) { return a < b ? a : b; }
    int findMinArrowShots(vector<vector<int>>& points) {
        vector<vector<int>>& d = points;
        sort(d.begin(), d.end(), cmp);
        int n = d.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int st = d[i][0], sp = d[i][1];
            while (i + 1 < n && sp >= d[i + 1][0]) { sp = min(sp, d[++i][1]); }
            ans++;
        }
        return ans;
    }
};

int main() {
    vector<int> x1 = { 10, 16};
    vector<int> x2 = { 2, 8 };
    vector<int> x3 = { 1, 6 };
    vector<int> x4 = { 7, 12 };
    vector<int> x5 = { 12, 16 };
    vector<int> x6 = { 4, 8 };
    vector<vector<int>> x = { x1,x2,x3,x4 };
    Solution s;
    auto ans = s.findMinArrowShots(x);
    cout << ans;
    return 0;
}
