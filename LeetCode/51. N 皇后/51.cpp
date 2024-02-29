#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	static const int MAXN = 9;
	int st[MAXN];
	bool vis[MAXN][MAXN];
	int N;
	vector<vector<string>> ans;
	void printCvis(bool *cvis, int dep, const char *s) {
		printf("%s, dep=%d, cvis=", s, dep);
		for (int i = 0; i < N; i++)
			printf("%d ", cvis[i]);
		printf("\n");
	}
	void addAns() {
		vector<string> tans(N);
		for (int i = 0; i < N; i++) {
			string s(N, '.');
			s[st[i]] = 'Q';
			tans[i] = s;
		}
		ans.push_back(tans);
	}
	bool inRange(const int &x) { return x >= 0 && x < N; }
	void dfs(int dep) {
		if (dep >= N) {
			addAns();
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
    vector<vector<string>> solveNQueens(int n) {
    	for (auto it = ans.begin(); it != ans.end(); it++)
    		it->clear();
    	ans.clear();
		N = n;
		dfs(0);
		return ans;
    }
};

int main() {
	Solution s;
	auto ans = s.solveNQueens(4);
	for (auto it = ans.begin(); it != ans.end(); it++) {
		for (auto it2 = it->begin(); it2 != it->end(); it2++) {
			printf("[%s], ", it2->c_str());
		}
		printf("\n");	
	}
	return 0;
}
