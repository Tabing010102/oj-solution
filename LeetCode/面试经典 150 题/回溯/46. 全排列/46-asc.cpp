#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void dfs(vector<int> &tans, const vector<int> &nums, vector<bool> &vis, vector<vector<int>> &ans, int cnt) {
        if (cnt >= tans.size()) {
            ans.push_back(tans);
        } else {
            for (int i = 0; i < nums.size(); i++) {
                if (!vis[i]) {
                    vis[i] = true;
                    tans[cnt] = nums[i];
                    dfs(tans, nums, vis, ans, cnt + 1);
                    vis[i] = false;
                }
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        vector<int> tans(nums.size());
        vector<bool> vis(tans.size(), false);
        dfs(tans, nums, vis, ans, 0);
        return ans; 
    }
};

int main() {
    vector<int> x = { 1, 5, 3 };
    Solution s;
    auto ans = s.permute(x);
    for (auto x : ans) {
        for (auto y : x) { cout << y << " "; }
        cout << endl;
    }
    return 0;
}
