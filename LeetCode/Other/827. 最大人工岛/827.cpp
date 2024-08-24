#include <bits/stdc++.h>

using namespace std;

const int MAXN = 500 + 10;
const int D[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

int v[MAXN][MAXN];
unordered_map<int, int> um;
unordered_set<int> us;
int n;

inline bool inRange(const int &x, const int &y) { return !(x < 0 || x >= n || y < 0 || y >= n); }
inline int max(const int &a, const int &b) { return a > b ? a : b; }

class Solution {
public:
	void dfs(vector<vector<int>>& G, int x, int y, int c) {
		if (!G[x][y] && v[x][y]) { return; }
		v[x][y] = c;
		for (int i = 0; i < 4; i++) {
			int tx = x + D[i][0], ty = y + D[i][1];
			if (!inRange(tx, ty)) { continue; }
			if (!G[tx][ty] || v[tx][ty]) { continue; }
			dfs(G, tx, ty, c);
		}
	}
    int largestIsland(vector<vector<int>>& grid) {
		vector<vector<int>>& G = grid;
		n = G.size();
		um.clear();
		memset(v, 0, sizeof(v));
		int c = 1;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (G[i][j] && !v[i][j]) {
					dfs(G, i, j, c++);
				}
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (v[i][j]) {
					if (um.find(v[i][j]) == um.end()) { um[v[i][j]] = 1; }
					else { um[v[i][j]]++; }
				}
			}
		}
		int ans = 0;
		for (auto it = um.begin(); it != um.end(); it++) { ans = max(ans, it->second); }
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (!G[i][j]) {
					int tans = 0;
					us.clear();
					for (int k = 0; k < 4; k++) {
						int x = i + D[k][0], y = j + D[k][1];
						if (!inRange(x, y)) { continue; }
						if (us.find(v[x][y]) != us.end()) { continue; }
						us.insert(v[x][y]);
						tans += um[v[x][y]];
					}
					ans = max(ans, tans + 1);
				}
			}
		}
		return ans;
    }
};

int main() {
	vector<int> x1 = { 1, 0 };
	vector<int> x2 = { 0, 1 };
	vector<vector<int> > x = { x1, x2 };
	Solution s;
	auto ans = s.largestIsland(x);
	cout << ans << endl;
	return 0;
}
