#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e4 + 10;

int vis[MAXN];
int n;

class Solution {
public:
    inline int min(const int &a, const int &b) { return a < b ? a : b; }
    void dfs(vector<int> &d, int idx) {
        if (vis[n - 1] != 0 || vis[idx] != 0) { return; }
        for (int i = min(n - 1, idx + d[idx]); vis[n - 1] == 0 && i > idx; i--) { dfs(d, i); }
        vis[idx] = 1;
    }
    bool canJump(vector<int>& nums) {
        n = nums.size();
        if (n <= 1) { return true; }
        memset(vis, 0, sizeof(vis));
        dfs(nums, 0);
        return vis[n - 1] == 1;
    }
};

int main() {
//    vector<int> x = {2,3,1,1,4};
    vector<int> x = {3,2,1,0,4};
    Solution s;
    auto ans = s.canJump(x);
    printf("%d ", ans);
    return 0;
}
