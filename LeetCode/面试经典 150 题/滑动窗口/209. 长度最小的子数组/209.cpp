#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    const int INF = 1e5 + 10;
    inline int min(const int &a, const int &b) { return a < b ? a : b; }
    int minSubArrayLen(int target, vector<int>& nums) {
        vector<int>& d = nums;
        int n = d.size();
        int l = 0, r = 0;
        int ans = INF;
        int cnt = d[l];
        while (1) {
            if (l == r && cnt >= target) { return 1; }
            while (r < n - 1 && cnt < target) { cnt += d[++r]; }
            if (cnt < target) { break; }
            while (cnt >= target && l < r) {
                ans = min(ans, r - l + 1);
                cnt -= d[l++];
            }
        }
        return ans == INF ? 0 : ans;
    }
};

int main() {
    vector<int> x = {2,3,1,2,4,3};
    Solution s;
    auto ans = s.minSubArrayLen(7, x);
    cout << ans << endl;
    return 0;
}
