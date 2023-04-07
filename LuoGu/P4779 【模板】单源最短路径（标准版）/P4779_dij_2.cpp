#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

const int MAXN = 200000+10;
const int INF = 0x7fffffff;

struct Edge {
	int from, to, dist;
};

vector<Edge> edges;
vector<int> G[MAXN];

void addEdge(int u, int v, int w) {
	int size = edges.size();
	edges.push_back((Edge){ u, v, w });
	G[u].push_back(size);
}

int n, m, s, d[MAXN], p[MAXN];

bool done[MAXN];

struct HeapNode {
	int u, d;
	bool operator < (const HeapNode &rhs) const {
		return d > rhs.d;
	}
};
priority_queue<HeapNode> pq;

int main() {
	scanf("%d%d%d", &n, &m, &s);
	for (int i = 0; i < m; i++) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		addEdge(u, v, w);
	}
	memset(d, 0, sizeof(d));
	
	for (int i = 1; i <= n; i++) d[i] = INF;
	memset(done, 0, sizeof(done));
	d[s] = 0;
	pq.push((HeapNode){ s, d[s] });
	while (!pq.empty()) {
		HeapNode x = pq.top(); pq.pop();
		int u = x.u;
		if (done[u]) continue;
		done[u] = true;
		for (int i = 0; i < G[u].size(); i++) {
			Edge &e = edges[G[u][i]];
			if (d[e.to] > d[u] + e.dist) {
				d[e.to] = d[u] + e.dist;
				p[e.to] = G[u][i];
				pq.push((HeapNode){ e.to, d[e.to] });
			}
		}
	}
	for (int i = 1; i <= n; i++) printf("%d ", d[i]);
}
