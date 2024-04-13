#include <bits/stdc++.h>

using namespace std;

const int INF = 1e4 + 10;
const int MAXN = 1e4 + 10;
int n;
int d[MAXN];
int dpv[MAXN];

class Solution {
public:
	int min(const int &a, const int &b) { return a < b ? a : b; }
	int dp(int c) {
		if (dpv[c] != -2) { return dpv[c]; }
		int minv = INF;
		for (int i = 0; i < n; i++) {
			if (d[i] <= c) {
				int f = dp(c - d[i]);
				if (f != -1) { minv = min(minv, f + 1); }
			}
		}
		if (minv == INF) { dpv[c] = -1; }
		else { dpv[c] = minv; }
		return dpv[c];
	}
    int coinChange(vector<int>& coins, int amount) {
    	n = coins.size();
    	for (int i = 0; i < n; i++) { d[i] = coins[i]; }
    	for (int i = 0; i <= amount; i++) { dpv[i] = -2; }
    	dpv[0] = 0;
		return dp(amount);
    }
};

int main() {
	Solution s;
//	vector<int> x = { 1,2,5 };
//	auto ans = s.coinChange(x, 11);
//	vector<int> x = { 2 };
//	auto ans = s.coinChange(x, 3);
	vector<int> x = { 1 };
	auto ans = s.coinChange(x, 0);
	cout << ans << endl;
	return 0;
}
