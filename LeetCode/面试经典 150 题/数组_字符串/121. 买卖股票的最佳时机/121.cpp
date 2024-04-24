#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    inline int max(const int &a, const int &b) { return a > b ? a : b; }
    int maxProfit(vector<int>& prices) {
        deque<int> dq;
        int ans = 0;
        int len = prices.size();
        if (len == 0) { return 0; }
        dq.push_back(prices[0]);
        for (int i = 1; i < len; i++) {
            int x = prices[i];
            if (x < dq.back()) {
                ans = max(ans, dq.back() - dq.front());
                while (!dq.empty() && x < dq.back()) { dq.pop_back(); }
                dq.push_back(x);
            } else {
                dq.push_back(x);
            }
        }
        if (!dq.empty()) {
            ans = max(ans, dq.back() - dq.front());
        }
        return ans;
    }
};

int main() {
    vector<int> x = {7,1,5,3,6,4};
    Solution s;
    auto ans = s.maxProfit(x);
    printf("%d ", ans);
    return 0;
}
