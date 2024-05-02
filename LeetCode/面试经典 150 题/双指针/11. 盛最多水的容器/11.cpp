#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    inline int max(const int &a, const int &b) { return a > b ? a : b; }
    inline int min(const int &a, const int &b) { return a < b ? a : b; }
    int maxArea(vector<int>& height) {
        vector<int>& d = height;
        int l = 0, r = d.size() - 1;
        int ans = min(d[l], d[r]) * (r - l);
        while (l < r) {
            ans = max(ans, min(d[l], d[r]) * (r - l));
            if (d[l] > d[r]) { r--; }
            else { l++; }
        }
        return ans;
    }
};

int main() {
    vector<int> x = {1,8,6,2,5,4,8,3,7};
    Solution s;
    auto ans = s.maxArea(x);
    cout << ans << ' ';
    return 0;
}
