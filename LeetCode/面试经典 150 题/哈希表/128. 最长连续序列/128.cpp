#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    inline int max(const int &a, const int &b) { return a > b ? a : b; }
    int longestConsecutive(vector<int>& nums) {
        vector<int>& d = nums;
        unordered_set<int> us;
        for (auto x : d) { if (us.find(x) == us.end()) { us.insert(x); } }
        int ans = 0;
        for (auto x : d) {
            if (us.find(x - 1) == us.end()) {
                int c = x;
                while (us.find(c) != us.end()) { c++; }
                ans = max(ans, c - x);
            }
        }
        return ans;
    }
};

int main() {
    vector<int> x = { 1,2,3,1,2,3 };
    Solution s;
    auto ans = s.longestConsecutive(x);
    cout << ans << " ";
    return 0;
}
