#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<int>& d = nums;
        int n = d.size();
        vector<string> ans;
        int p = 0;
        while (p < n) {
            int p0 = p;
            int cnt = d[p];
            while (p < n - 1 && d[p + 1] == cnt + 1) { p++; cnt++; }
            stringstream ss;
            if (p0 == p) {
                ss << d[p];
                ans.push_back(ss.str());
            } else {
                ss << d[p0] << "->" << d[p];
                ans.push_back(ss.str());
            }
            p++;
        }
        return ans;
    }
};

int main() {
    vector<int> x = { 0,2,3,4,6,8,9 };
    Solution s;
    auto ans = s.summaryRanges(x);
    for (auto s : ans) { cout << s << " "; }
    return 0;
}
