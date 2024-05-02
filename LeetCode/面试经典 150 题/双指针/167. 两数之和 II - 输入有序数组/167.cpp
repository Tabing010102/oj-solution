#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        for (auto it = numbers.begin(); it != numbers.end(); it++) {
            auto p = upper_bound(numbers.begin(), numbers.end(), target - *it);
            p--;
            if (*it + *p != target) { continue; }
            vector<int> ans;
            ans.push_back(it - numbers.begin() + 1);
            ans.push_back(p - numbers.begin() + 1);
            return ans;
        }
        return vector<int>();
    }
};

int main() {
    vector<int> x = {2,7,11,15};
    Solution s;
    auto ans = s.twoSum(x, 9);
    for (auto x : ans) { cout << x << ' '; }
    return 0;
}
