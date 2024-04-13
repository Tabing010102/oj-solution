#include <bits/stdc++.h>

using namespace std; 

const int MAXN = 5000 + 10;
const int INF = 0x3f3f3f3f;

struct Edge {
	int from, to, dist;
	Edge(int from, int to, int dist) {
		this->from = from;
		this->to = to;
		this->dist = dist;
	}
};

struct HNode {
	int u, d;
	HNode(int u, int d) {
		this->u = u;
		this->d = d;
	}
	bool operator < (const HNode &rhs) const {
		return this->d > rhs.d;
	}
};

vector<int> G[MAXN];
vector<Edge> edges;
int d[MAXN];
bool vis[MAXN];

class Solution {
public:
	bool canReach(const string &a, const string &b) {
		int len = a.size();
		int diff = 0;
		for (int i = 0; i < len; i++) {
			if (diff > 1) { return false; }
			else if (a[i] == b[i]) { continue; }
			else { diff++; }
		}
		return diff == 1;
	}
	void AddEdge(int from, int to) {
		edges.push_back(Edge(from, to, 1));
		edges.push_back(Edge(to, from, 1));
		int len = edges.size();
		G[from].push_back(len - 2);
		G[to].push_back(len - 1);
	}
	void clear(int n) {
		for (int i = 0; i < n; i++) { G[i].clear(); }
		edges.clear();
	}
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
		int n = wordList.size();
		int s = -1, e = -1;
		for (int i = 0; i < n; i++) {
			if (s != -1 && e != -1) { break; }
			else if (s == -1 && wordList[i] == beginWord) { s = i; }
			else if (e == -1 && wordList[i] == endWord) { e = i; }
		}
		if (e == -1) { return 0; }
		if (s == -1) {
			wordList.push_back(beginWord);
			s = n;
			n++;
		}
		clear(n);
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				if (canReach(wordList[i], wordList[j])) {
					AddEdge(i, j);
				}
			}
		}
		for (int i = 0; i < n; i++) { d[i] = INF; }
		d[s] = 0;
		memset(vis, 0, sizeof(vis));
		priority_queue<HNode> pq;
		pq.push(HNode(s, 0));
		while (!pq.empty()) {
			int u = pq.top().u;
			pq.pop();
			if (vis[u]) { continue; }
			vis[u] = true;
			for (auto it = G[u].begin(); it != G[u].end(); it++) {
				Edge &e = edges[*it];
				if (!vis[e.to] && d[e.to] > d[u] + e.dist) {
					d[e.to] = d[u] + e.dist;
					pq.push(HNode(e.to, d[e.to]));
				}
			}
		}
		if (d[e] >= INF) { return 0; }
		else { return d[e] + 1; }
    }
};

int main() {
	Solution s;
//	vector<string> x = { "hot","dot","dog","lot","log","cog" };
//	auto ans = s.ladderLength("hit", "cog", x);
	vector<string> x = { "hot","dog" };
	auto ans = s.ladderLength("hot", "dog", x);
	cout << ans << endl;
	return 0;
}
