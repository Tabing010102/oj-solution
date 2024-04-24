#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    inline int max(const int &a, const int &b) { return a > b ? a : b; }
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if (len == 0) { return 0; }
        // f[n][0] = max(f[n-1][0], f[n-1][1] + prices[n - 1]);
        // f[n][1] = max(f[n-1][1], f[n-1][0] - prices[n - 1]);
        int f0 = 0, f1 = -prices[0];
        for (int i = 0; i < len; i++) {
            int fn0 = max(f0, f1 + prices[i]);
            int fn1 = max(f1, f0 - prices[i]);
            f0 = fn0;
            f1 = fn1;
        }
        return max(0, f0);
    }
};

int main() {
    vector<int> x = {7,1,5,3,6,4};
    Solution s;
    auto ans = s.maxProfit(x);
    printf("%d ", ans);
    return 0;
}
