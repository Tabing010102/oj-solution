#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e4 + 10;

int dp[MAXN];

class Solution {
public:
    int max(const int &a, const int &b) { return a > b ? a : b; }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) { dp[i] = 1; }
        int ans = 1;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                    ans = max(ans, dp[i]);
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
//    vector<int> x = { 10,9,2,5,3,7,101,18 };
//    vector<int> x = { 0,1,0,3,2,3 };
//    vector<int> x = { 7,7,7,7,7,7,7 };
    vector<int> x = { 1,3,6,7,9,4,10,5,6 };
    auto ans = s.lengthOfLIS(x);
    cout << ans << endl;
    return 0;
}
