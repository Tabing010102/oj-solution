#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) { m[nums[i]] = i; }
        for (int i = 0; i < nums.size(); i++) {
            int t = target - nums[i];
            if (m.find(t) != m.end() && i != m[t]) {
                ans.push_back(i);
                ans.push_back(m[t]);
                return ans;
            }
        }
        return ans;
    }
};

int main() {
    vector<int> x = {11, 2, 7, 15};
    Solution s;
    auto ans = s.twoSum(x, 9);
    for (auto x : ans) { cout << x << " "; }
    return 0;
}
