#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        vector<int>& d = nums;
        int n = d.size();
        unordered_map<int, int> um;
        for (int i = 0; i < n; i++) {
            int cnt = d[i];
            if (um.find(cnt) != um.end()) {
                if (i - um[cnt] <= k) { return true; }
                else { um[cnt] = i; }
            } else {
                um[cnt] = i;
            }
        }
        return false;
    }
};

int main() {
    vector<int> x = { 1,2,3,1,2,3 };
    Solution s;
    auto ans = s.containsNearbyDuplicate(x, 2);
    cout << ans << " ";
    return 0;
}
