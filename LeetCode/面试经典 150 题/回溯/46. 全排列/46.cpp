#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void dfs(vector<int> &tans, vector<vector<int>> &ans, int cnt) {
        if (cnt >= tans.size()) {
            ans.push_back(tans);
        } else {
            for (int i = cnt; i < tans.size(); i++) {
                swap(tans[i], tans[cnt]);
                dfs(tans, ans, cnt + 1);
                swap(tans[i], tans[cnt]);
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> tans = nums;
        dfs(tans, ans, 0);
        return ans; 
    }
};

int main() {
    vector<int> x = { 1, 2, 3 };
    Solution s;
    auto ans = s.permute(x);
    for (auto x : ans) {
        for (auto y : x) { cout << y << " "; }
        cout << endl;
    }
    return 0;
}
