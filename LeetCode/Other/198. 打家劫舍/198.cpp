#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100 + 10;
int dpv[2][MAXN];

class Solution {
public:
	int dp(int i, int j, vector<int>& d) {
		if (j < 0) { return 0; }
		else if (dpv[i][j] >= 0) { return dpv[i][j]; }
		else {
			if (i == 0) { return dpv[0][j] = max(dp(1, j - 1, d), dp(0, j - 1, d)); }
			else { return dpv[1][j] = dp(0, j - 1, d) + d[j]; }
		}
	}
	int max(const int &a, const int &b) { return a > b ? a : b; }
    int rob(vector<int>& d) {
		memset(dpv, -1, sizeof(dpv));
		dpv[0][0] = 0;
		dpv[1][0] = d[0];
		int ans = max(dp(0, d.size() - 1, d), dp(1, d.size() - 1, d));
//		for (int i = 0; i < d.size(); i++) { printf("%d %d\n", dpv[0][i], dpv[1][i]); }
		return ans;
    }
};

int main() {
	Solution s;
//	vector<int> x = { 1,2,3,1 };
//	vector<int> x = { 2,7,9,3,1 };
//	vector<int> x = { 2,1,1,2 };
	vector<int> x = { 1,2,3,1 };
	auto ans = s.rob(x);
	cout << ans << endl;
	return 0;
}
