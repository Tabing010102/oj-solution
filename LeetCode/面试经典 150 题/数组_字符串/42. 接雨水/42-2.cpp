#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    inline int min(const int &a, const int &b) { return a < b ? a : b; }
    inline int max(const int &a, const int &b) { return a > b ? a : b; }
    int trap(vector<int>& height) {
        deque<int> dq;
        int ans = 0;
        for (int i = 0; i < height.size(); i++) {
            int cnt = height[i];
            if (dq.empty() || height[dq.back()] > cnt) { dq.push_back(i); }
            else if (height[dq.back()] == cnt) {
                dq.pop_back();
                dq.push_back(i);
            } else {
                // current notch
                while (!dq.empty() && height[dq.back()] < cnt) {
                    int m = dq.back();
                    dq.pop_back();
                    if (!dq.empty()) {
                        int l = dq.back() + 1;
                        ans += (min(cnt, height[l - 1]) - height[m]) * (i - l);
                    }
                }
                while (!dq.empty() && height[dq.back()] == cnt) { dq.pop_back(); }
                dq.push_back(i);
            }
        }
        return ans;
    }
};

int main() {
//    vector<int> x = {0,1,0,2,1,0,1,3,2,1,2,1};
    vector<int> x = {4,2,0,3,2,5};
    Solution s;
    auto ans = s.trap(x);
    printf("%d ", ans);
    return 0;
}
