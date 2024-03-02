#include <bits/stdc++.h>

using namespace std;

struct Node {
	int v;
	Node *lc, *rc;
	Node() {}
	Node(const int &v): v(v) {}
	Node(const int &v, Node *lc, Node *rc): v(v), lc(lc), rc(rc) {}
};

class Solution {
public:
	vector<vector<int> > G;
	bool *vis;
	int ans = 0;
	void dfs(int u) {
		if (vis[u]) return;
		vis[u] = true;
		ans++;
		for (auto it = G[u].begin(); it != G[u].end(); it++) {
			int v = *it;
			if (vis[v]) continue;
			else dfs(v);
		}
	}
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
    	vis = new bool[n];
    	memset(vis, 0, sizeof(bool) * n);
    	for (auto it = restricted.begin(); it != restricted.end(); it++) { vis[*it] = true; }
    	G.clear(); G.resize(n);
        for (auto it = edges.begin(); it != edges.end(); it++) {
        	int u = (*it)[0], v = (*it)[1];
        	G[u].push_back(v);
        	G[v].push_back(u);
        }
        ans = 0;
        dfs(0);
        delete [] vis;
        return ans;
    }
};

int main() {
	int e[6][2] = { {0, 1}, {1, 2}, {3, 1}, {4, 0}, {0, 5}, {5, 6}};
	vector<vector<int>> ev;
	for (int i = 0; i < 6; i++) {
		vector<int> x(e[i], e[i] + 2);
		ev.push_back(x);
	}
	vector<int> r = { 4, 5 };
	Solution s;
	auto ans = s.reachableNodes(7, ev, r);
	cout << ans << endl;
	return 0;
}
