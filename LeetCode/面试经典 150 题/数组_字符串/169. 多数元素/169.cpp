#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 10;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if (nums.size() == 1) { return nums[0]; }
        sort(nums.begin(), nums.end());
        int last = INF;
        for (auto it = nums.begin(); it != nums.end(); it++) {
            if (*it != last) {
                last = *it;
                continue;
            } else {
                int d = 1;
                while (it != nums.end() && *it == last) { it++; d++; }
                if (d > nums.size() / 2) { return last; }
                it--;
            }
        }
        return INF;
    }
};

int main() {
//    vector<int> x = {2,2,1,1,1,2,2};
    vector<int> x = {1, 1};
    Solution s;
    auto ans = s.majorityElement(x);
    printf("%d", ans);
    return 0;
}
