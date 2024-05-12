#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>& d = intervals;
        vector<vector<int>> ans;
        int n = d.size();
        if (n == 0) {
            ans.push_back(newInterval);
            return ans;
        }
        int p = 0;
        while (p < n && d[p][1] < newInterval[0]) { ans.push_back(d[p++]); }
        if (p < n && d[p][0] > newInterval[1]) {
            ans.push_back(newInterval);
        } else if (p < n) {
            int st = min(d[p][0], newInterval[0]), sp = max(d[p][1], newInterval[1]);
            while (p < n && d[p][1] <= sp) { p++; }
            if (p < n && d[p][0] <= newInterval[1]) {
                sp = max(sp, d[p][1]);
                p++;
            }
            vector<int> x = { st, sp };
            ans.push_back(x);
        } else {
            ans.push_back(newInterval);
        }
        while (p < n && d[p][0] > newInterval[1]) { ans.push_back(d[p++]); }
        return ans;
    }
};

int main() {
    vector<int> x1 = { 1, 2 };
    vector<int> x2 = { 3, 5 };
    vector<int> x3 = { 6, 7 };
    vector<int> x4 = { 8, 10 };
    vector<int> x5 = { 12, 16 };
    vector<int> x6 = { 4, 8 };
    vector<vector<int>> x = { x1, x2, x3, x4, x5 };
    Solution s;
    auto ans = s.insert(x, x6);
    for (auto x : ans) { cout << x[0] << " " << x[1] << endl; }
    return 0;
}
