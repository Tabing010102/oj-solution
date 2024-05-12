#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    static bool cmp(const vector<int> &a, const vector<int> &b) {
        if (a[0] != b[0]) { return a[0] < b[0]; }
        else { return a[1] < b[1]; }
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>& d = intervals;
        sort(d.begin(), d.end(), cmp);
        int n = d.size();
        vector<vector<int>> ans;
        int p = 0;
        while (p < n) {
            vector<int> &cntv = d[p];
            int st = cntv[0], sp = cntv[1];
            while (p + 1 < n && d[p + 1][0] <= sp) {
                p++;
                sp = max(sp, d[p][1]);
            }
            vector<int> tans = { st, sp };
            ans.push_back(tans);
            p++;
        }
        return ans;
    }
};

int main() {
    vector<int> x1 = { 1, 3 };
    vector<int> x2 = { 2, 6 };
    vector<int> x3 = { 8, 10 };
    vector<int> x4 = { 15, 18 };
    vector<vector<int>> x = { x1, x2, x3, x4 };
    Solution s;
    auto ans = s.merge(x);
    for (auto x : ans) { cout << x[0] << " " << x[1] << endl; }
    return 0;
}
