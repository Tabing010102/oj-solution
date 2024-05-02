#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int>& d = numbers;
        int l = 0, r = d.size() - 1;
        vector<int> ans = {0, 0};
        while (l < r) {
            if (d[l] + d[r] == target) {
                ans[0] = l + 1;
                ans[1] = r + 1;
                break;
            } else if (d[l] + d[r] < target) {
                l++;
            } else {
                r--;
            }
        }
        return ans;
    }
};

int main() {
    vector<int> x = {2,7,11,15};
    Solution s;
    auto ans = s.twoSum(x, 9);
    for (auto x : ans) { cout << x << ' '; }
    return 0;
}
