#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e4 + 10;

int f[MAXN];
int n;

class Solution {
public:
    inline int min(const int &a, const int &b) { return a < b ? a : b; }
    int jump(vector<int>& nums) {
        n = nums.size();
        if (n <= 1) { return 0; }
        memset(f, 0x3f, sizeof(f));
        f[0] = 0;
        for (int i = 0; i < n - 1; i++) {
            for (int j = min(n - 1, i + nums[i]); j > i; j--) {
                if (f[j] < f[i] + 1) { continue; }
                else { f[j] = f[i] + 1; }
            }
        }
        return f[n - 1];
    }
};

int main() {
//    vector<int> x = {2,3,1,1,4};
    vector<int> x = {2,3,0,1,4};
    Solution s;
    auto ans = s.jump(x);
    printf("%d ", ans);
    return 0;
}
