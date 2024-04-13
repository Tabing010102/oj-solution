#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	static const int MAXN = 9;
	int st[MAXN];
	bool vis[MAXN][MAXN];
	int N, ans;
	void printCvis(bool *cvis, int dep, const char *s) {
		printf("%s, dep=%d, cvis=", s, dep);
		for (int i = 0; i < N; i++)
			printf("%d ", cvis[i]);
		printf("\n");
	}
	bool inRange(const int &x) { return x >= 0 && x < N; }
	void dfs(int dep) {
		if (dep >= N) {
			ans++;
			return;
		}
		bool *cvis = vis[dep];
		memset(cvis, 0, sizeof(bool) * N);
//		printCvis(cvis, dep, "[B]");
		for (int i = 0; i < dep; i++) {
			int x = st[i];
			cvis[x] = true;
			if (inRange(x - (dep - i))) cvis[x - (dep - i)] = true;
			if (inRange(x + (dep - i))) cvis[x + (dep - i)] = true;
		}
//		printCvis(cvis, dep, "[A]");
		for (int i = 0; i < N; i++)
			if (!cvis[i]) {
				st[dep] = i;
				dfs(dep + 1);
			}
	}
    int totalNQueens(int n) {
		N = n;
		ans = 0;
		dfs(0);
		return ans;
    }
};

int main() {
	Solution s;
	auto ans = s.totalNQueens(1);
	cout << ans << endl;
	return 0;
}
