#include <bits/stdc++.h>

using namespace std;

const int MAXN = 45 + 5;
int d[MAXN];

class Solution {
public:
	int dp(int c) {
		if (c < 0) { return 0; }
		else if (d[c] > 0) { return d[c]; }
		else if (c == 1) { return d[c] = 1; }
		else if (c == 2) { return d[c] = 2; }
		else { return d[c] = dp(c - 1) + dp(c - 2); }
	}
    int climbStairs(int n) {
		memset(d, 0, sizeof(d));
		return dp(n);
    }
};

int main() {
	Solution s;
//	auto ans = s.climbStairs(3);
	auto ans = s.climbStairs(45);
	cout << ans << endl;
	return 0;
}
