#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const int MOD = 1e9 + 7;
const int MAXN = 3000 + 10;
const int MAXK = 1000 + 10;
int start;
int lowL, highL;
int dpv[MAXN][MAXK];

class Solution {
public:
	int dp(int pos, int k) {
		if (pos < lowL || pos > highL) return 0;
		if (dpv[pos][k] != -1) return dpv[pos][k];
		LL ansLL = dp(pos - 1, k - 1) + dp(pos + 1, k - 1);
		int ans = (int)(ansLL % MOD);
		dpv[pos][k] = ans;
		return ans;
	}
    int numberOfWays(int startPos, int endPos, int k) {
    	int l = startPos > endPos ? endPos : startPos;
    	int r = startPos <= endPos ? endPos : startPos;
    	start = l + 1000;
    	lowL = start - k;
    	highL = start + k;
    	memset(dpv, -1, sizeof(dpv));
    	for (int i = lowL; i <= highL; i++) dpv[i][0] = 0;
    	dpv[start][0] = 1;
    	dpv[start - 1][0] = 0; dpv[start - 1][1] = 1;
    	dpv[start + 1][0] = 0; dpv[start + 1][1] = 1;
        return dp(r + 1000, k);
    }
};

int main() {
	Solution s;
//	auto ans = s.numberOfWays(1, 2, 3);
//	auto ans = s.numberOfWays(2, 5, 10);
	auto ans = s.numberOfWays(989, 1000, 99);
	cout << ans << endl;
	return 0;
}
