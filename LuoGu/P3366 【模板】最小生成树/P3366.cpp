#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 5000+10;
const int MAXM = 400000+10;

struct Edge {
	int from, to, dist;
};

vector<Edge> edges;
//vector<int> G[MAXN];
int n, m;
int r[MAXM];
int fa[MAXN];
int ans;

bool cmp(const int &a, const int &b) { return edges[a].dist < edges[b].dist; }

void addEdge(int from, int to, int dist) {
//	int s = edges.size();
	edges.push_back((Edge){from, to, dist});
	edges.push_back((Edge){to, from, dist});
//	G[from].push_back(s);
//	G[to].push_back(s+1);
}

int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		int f, t, d;
		scanf("%d%d%d", &f, &t, &d);
		addEdge(f, t, d);
	}
//	m *= 2;
//	for (auto it = edges.begin(); it != edges.end(); it++) {
//		printf("%d %d -> %d\n", it->from, it->to, it->dist);
//	}
	for (int i = 0; i < m+m; i++) r[i] = i;
	sort(r, r+m+m, cmp);
	for (int i = 0; i < n; i++) fa[i] = i;
	ans = 0;
	for (int i = 0; i < m+m; i++) {
		int e = r[i];
		int fa1 = find(edges[e].from);
		int fa2 = find(edges[e].to);
		if (fa1 != fa2) {
			ans += edges[e].dist;
			fa[fa1] = fa2;
		}
	}
	bool flag = true;
	int fag = find(0);
	for (int i = 0; i < n; i++)
		if (find(i) != fag) {
			flag = false;
			break;
		}
	if (flag) printf("%d", ans);
	else printf("orz");
	return 0;
}
