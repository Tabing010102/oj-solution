#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2500+10;
int dp[MAXN];
vector<int> d;

class Solution {
public:
	int max(const int &a, const int &b) { return a > b ? a : b; }
    int lengthOfLIS(vector<int>& nums) {
    	int size = nums.size();
		memset(dp, 0, sizeof(dp));
		for (int i = 0; i < size; i++) {
			dp[i] = 1;
			for (int j = 0; j < i; j++)
				if (nums[i] > nums[j]) {
//					printf("nums[%d]=%d, nums[%d]=%d\n", i, nums[i], j, nums[j]);
					dp[i] = max(dp[i], dp[j] + 1);
//					printf("dp[%d]=%d, dp[%d]=%d\n", i, dp[i], j, dp[j]);
				}
		}
		int ans = 0;
		for (int i = 0; i < size; i++)
			ans = max(ans, dp[i]);
		return ans;
    }
};

int main() {
//	d.push_back(10);
//	d.push_back(9);
//	d.push_back(2);
//	d.push_back(5);
//	d.push_back(3);
//	d.push_back(7);
//	d.push_back(101);
//	d.push_back(18);
	d.push_back(0);
	d.push_back(1);
	d.push_back(0);
	d.push_back(3);
	d.push_back(2);
	d.push_back(3);
	Solution s;
	cout << s.lengthOfLIS(d);
	return 0;
}
