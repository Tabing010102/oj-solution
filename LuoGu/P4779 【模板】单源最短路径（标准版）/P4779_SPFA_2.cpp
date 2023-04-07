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

bool inq[MAXN];
int inqc[MAXN];
queue<int> q;

int main() {
	scanf("%d%d%d", &n, &m, &s);
	for (int i = 0; i < m; i++) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		addEdge(u, v, w);
	}
	memset(d, 0, sizeof(d));
	
	memset(inq, 0, sizeof(inq));
	memset(inqc, 0, sizeof(inqc));
	for (int i = 1; i <= n; i++) d[i] = INF;
	bool failed = false;
	d[s] = 0;
	q.push(s);
	inq[s] = true; inqc[s]++;
	while (!q.empty()) {
		int u = q.front(); q.pop();
		inq[u] = false;
		if (++inqc[u] > n) { failed = true; break; }
		for (int i = 0; i < G[u].size(); i++) {
			Edge &e = edges[G[u][i]];
			if (d[e.to] > d[u] + e.dist) {
				d[e.to] = d[u] + e.dist;
				p[e.to] = G[u][i];
				if (!inq[e.to]) {
					q.push(e.to);
					inq[e.to] = true;
				}
			}
		}
	}
	if (failed) printf("G");
	for (int i = 1; i <= n; i++) printf("%d ", d[i]);
}
