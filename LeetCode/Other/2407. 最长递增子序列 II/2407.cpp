#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 10;

int f[MAXN];

inline int max(const int &a, const int &b) { return a > b ? a : b; }

class Solution {
public:
    int lengthOfLIS(vector<int>& nums, int k) {
        memset(f, 0, sizeof(f));
        vector<int>& d = nums;
        int n = d.size();
        for (int i = 0; i < n; i++) { f[i] = 1; }
        int ans = 1;
        for (int i = 1; i < n; i++) {
        	for (int j = 0; j < i; j++) {
        		if (d[i] > d[j] && d[i] - d[j] <= k) {
        			f[i] = max(f[i], f[j] + 1);
        			ans = max(ans, f[i]);
        		}
        	}
        }
        return ans;
    }
};

int main() {
	Solution s;
	vector<int> a = {4,2,1,4,3,4,5,8,15};
	auto ans = s.lengthOfLIS(a, 3);
	printf("%d\n", ans);
	return 0;
}
