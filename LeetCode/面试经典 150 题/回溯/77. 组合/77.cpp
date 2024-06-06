#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void dfs(vector<int> &tans, int idx, int cnt, const int &n, const int &k, vector<vector<int>> &ans) {
        if (cnt == k) {
            ans.push_back(tans);
        } else {
            for (int i = idx; i <= n - (k - cnt - 1); i++) {
                tans.push_back(i);
                dfs(tans, i + 1, cnt + 1, n, k, ans); 
                tans.pop_back();
            }
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> tans;
        dfs(tans, 1, 0, n, k, ans);
        return ans;
    }
};

int main() {
    Solution s;
    auto ans = s.combine(4, 2);
    for (auto x : ans) {
        for (auto y : x) { cout << y << " "; }
        cout << endl;
    }
    return 0;
}
