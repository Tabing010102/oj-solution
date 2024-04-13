#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int MAXN = 200;
const LL INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;
LL G[MAXN][MAXN], d[MAXN][MAXN];
int dpv[MAXN];
int N;

class Solution {
public:
	int dp(int p) {
		if (dpv[p] != -1) return dpv[p];
		dpv[p] = 0;
		for (int i = 0; i < N; i++)
			if (G[p][i] && d[0][p] == d[0][i] + G[i][p])
				dpv[p] = (int)(((LL)(dpv[p] % MOD) + (dp(i) % MOD)) % MOD);
		return dpv[p];
	}
    int countPaths(int n, vector<vector<int>>& roads) {
    	N = n;
    	// init G, d
    	memset(G, 0, sizeof(G));
    	for (int i = 0; i < n; i++)
    		for (int j = 0; j < n; j++)
    			d[i][j] = INF;
    	for (int i = 0; i < n; i++) d[i][i] = 0;
    	// add edges
		for (auto it = roads.begin(); it != roads.end(); it++) {
			vector<int> &edge = *it;
			for (int i = 0; i < 3; i++) {
				int u = edge[0], v = edge[1], dist = edge[2];
				G[u][v] = dist;
				G[v][u] = dist;
				d[u][v] = dist;
				d[v][u] = dist;
			}
		}
		// floyed
		for (int i = 0; i < n; i++)
    		for (int j = 0; j < n; j++)
    			for (int k = 0; k < n; k++)
    				if (d[i][j] > d[i][k] + d[k][j])
    					d[i][j] = d[i][k] + d[k][j];
    	// init dpv
    	for (int i = 0; i < n; i++) dpv[i] = -1;
    	dpv[0] = 1;
    	int ans = dp(n - 1);
    	return ans;
    }
};

int main() {
	Solution s;
	int x[][3] = {
		{0,6,7},{0,1,2},{1,2,3},{1,3,3},{6,3,3},{3,5,1},{6,5,1},{2,5,1},{0,4,5},{4,6,2}
	};
	vector<vector<int> > v;
	for (int i = 0; i < 10; i++) {
		vector<int> a(x[i], x[i] + 3);
		v.push_back(a);
	}
	auto ans = s.countPaths(7, v);
	cout << ans << endl;
	return 0;
}
