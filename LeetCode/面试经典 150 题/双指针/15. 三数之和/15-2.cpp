#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<int>& d = nums;
        sort(d.begin(), d.end());
        int n = d.size();
        int i = 0;
        vector<vector<int>> ans;
        while (i <= n - 3) {
            int d0 = d[i];
            int l = i + 1, r = n - 1;
//            while (l < r && d0 == d[l]) { l++; }
            while (l < r) {
                while (l < r && d0 + d[l] + d[r] < 0) { l++; }
                while (l < r && d0 + d[l] + d[r] > 0) { r--; }
                if (l < r && d0 + d[l] + d[r] == 0) {
                    vector<int> t = { d0, d[l], d[r] };
                    ans.push_back(t);
                    int dl = d[l], dr = d[r];
                    while (l < r && d[l] == dl) { l++; }
                    while (l < r && d[r] == dr) { r--; }
                }
            }
            // move to next
            while (i <= n - 3 && d0 == d[i]) { i++; }
        }
        return ans;
    }
};

int main() {
//    vector<int> x = {-1,0,1,2,-1,-4};
    vector<int> x = {1,2,-2,-1};
    Solution s;
    auto ans = s.threeSum(x);
    for (auto a : ans) {
        for (auto b : a) { cout << b << ' '; }
        cout << endl;
    }
    return 0;
}
