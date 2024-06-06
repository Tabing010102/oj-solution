#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void dfs(vector<int> &tans, const vector<int> &d, int idx, int sum, vector<vector<int>> &ans, const int target) {
        if (sum >= target || idx >= d.size()) {
            if (sum == target) {
                vector<int> a;
                for (int i = 0; i < tans.size(); i++) {
                    for (int j = 0; j < tans[i]; j++) {
                        a.push_back(d[i]);
                    }
                }
                ans.push_back(a);
            }
        } else {
//            printf("target=%d, sum=%d, idx=%d, d[idx]=%d, max(0, (target - sum) / d[idx])=%d\n", target, sum, idx, d[idx], max(0, (target - sum) / d[idx]));
            for (int i = max(0, (target - sum) / d[idx]); i >= 0; i--) {
                tans[idx] = i;
                dfs(tans, d, idx + 1, sum + d[idx] * i, ans, target);
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> tans(candidates.size(), 0);
        vector<vector<int>> ans;
        sort(candidates.begin(), candidates.end(), greater<int>());
        dfs(tans, candidates, 0, 0, ans, target);
        return ans;
    }
};

int main() {
    vector<int> x = { 2,3,6,7 };
    Solution s;
    auto ans = s.combinationSum(x, 7);
    for (auto x : ans) {
        for (auto y : x) { cout << y << " "; }
        cout << endl;
    }
    return 0;
}
