#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

const int MAXN = 100000+10;
const int MAXM = 200000+10;
const int INF = 0x7fffffff;

struct Edge {
	int from, to, dist;
};

vector<Edge> edges;
vector<int> G[MAXN];
int n, m, s;
int d[MAXN];

struct HeapNode {
	int u, d;
	bool operator < (const HeapNode &rhs) const {
		return d > rhs.d;
	}
};

priority_queue<HeapNode> pq;
int p[MAXN];
bool done[MAXN];

void addEdge(int from, int to, int dist) {
	int s = edges.size();
	edges.push_back((Edge){ from, to, dist });
	G[from].push_back(s);
}

int main() {
	scanf("%d%d%d", &n, &m, &s);
	for (int i = 0; i < m; i++) {
		int f, t, d;
		scanf("%d%d%d", &f, &t, &d);
		addEdge(f, t, d);
	}
	
	for (int i = 1; i <= n; i++) d[i] = INF;
	d[s] = 0;
	memset(p, 0, sizeof(p));
	memset(done, 0, sizeof(done));
	pq.push((HeapNode){ s, 0 });
	while (!pq.empty()) {
		HeapNode x = pq.top(); pq.pop();
		int u = x.u;
		if (done[u]) continue;
		done[u] = true;
		for (auto it = G[u].begin(); it != G[u].end(); it++) {
			Edge &e = edges[*it];
			if (d[e.to] > d[u] + e.dist) {
				d[e.to] = d[u] + e.dist;
				p[e.to] = *it;
				pq.push((HeapNode){ e.to, d[e.to] });
			}
		}
	}
	for (int i = 1; i <= n; i++) printf("%d ", d[i]);
	return 0;
}
