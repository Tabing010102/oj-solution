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
int inqc[MAXN];
bool inq[MAXN];
int p[MAXN];
queue<int> q;

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
	memset(inq, 0, sizeof(inqc));
	memset(inq, 0, sizeof(inq));
	memset(inq, 0, sizeof(p));
	q.push(s);
	inq[s] = true;
	bool failed = false;
	while (!q.empty()) {
		int u = q.front(); q.pop();
		inq[u] = false;
		if (++inqc[u] > n) { failed = true; break; }
		for (auto it = G[u].begin(); it != G[u].end(); it++) {
			Edge &e = edges[*it];
			if (d[e.to] > d[u] + e.dist) {
				d[e.to] = d[u] + e.dist;
				p[e.to] = *it;
				if (inq[e.to] == false) {
					q.push(e.to);
					inq[e.to] = true;
				}
			}
		}
	}
	if (failed) printf("?");
	for (int i = 1; i <= n; i++) printf("%d ", d[i]);
	return 0;
}
