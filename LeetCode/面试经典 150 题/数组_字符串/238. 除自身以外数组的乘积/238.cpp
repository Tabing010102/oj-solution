#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        ans.resize(n);
        int last = 1;
        for (int i = n - 1; i >= 0; i--) {
            last *= nums[i];
            ans[i] = last;
        }
        last = 1;
        for (int i = 0; i < n; i++) {
            ans[i] = last * (i < n - 1 ? ans[i + 1] : 1);
            last *= nums[i];
        }
        return ans;
    }
};

int main() {
    vector<int> x = {1,2,3,4};
    Solution s;
    auto ans = s.productExceptSelf(x);
    for (auto x : ans) { printf("%d ", x); }
    return 0;
}
