#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

const int MAXN = 500 + 10;
const int MAXNS = MAXN * MAXN;
const int INF = 0x3f3f3f3f;
const int detla[4][2] = { {0, -1}, {0, 1}, {-1, 0}, {1, 0} } ;

struct Node {
	int x, y, fc;
	Node (int x, int y, int fc) : x(x), y(y), fc(fc) {}
};

char buf[MAXN];
bool G[MAXN][MAXN];
//int d[MAXNS][MAXNS];
int m, n, ns;
int sx, sy, tx, ty;
int f[MAXN][MAXN][5];
queue<Node> q;

inline int gx(const int &x) { return (x / n) + 1; }
inline int gy(const int &x) { return (x % n) + 1; }
inline int gi(const int &x, const int &y) { return (x - 1) * n + y - 1; }
inline int gax(const int &x) { return n + 1 - x; }
inline int gay(const int &y) { return m + 1 - y; }

inline int min(const int &a, const int &b) { return a < b ? a : b; }

int main() {
	scanf("%d%d", &n, &m);
	ns = n * m;
	for (int i = 0; i < n; i++) {
		scanf("%s", buf);
		for (int j = 0; j < m; j++) {
			G[i + 1][j + 1] = buf[j] != '#';
			if (buf[j] == 'S') { sx = i + 1; sy = j + 1; }
			if (buf[j] == 'E') { tx = i + 1; ty = j + 1; }
		}
	}
//	memset(d, 0x3f, sizeof(d));
//	for (int i = 1; i <= ns; i++) {
//		if (G[gx(i)][gy(i)]) { d[i][i] = 0; }
//	}
//	for (int k = 1; k <= ns; k++) {
//		if (G[gx(k)][gy(k)]) for (int i = 1; i <= ns; i++) {
//			if (G[gx(i)][gy(i)]) for (int j = 1; j <= ns; j++) {
//				if (G[gx(j)][gy(j)] && d[i][k] < INF && d[k][j] < INF) {
//					G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
//				}
//			}
//		}
//	}
	memset(f, 0x3f, sizeof(f));
	f[sx][sy][0] = f[sx][sy][1] = f[sx][sy][2] = f[sx][sy][3] = f[sx][sy][4] = 0;
	q.push(Node(sx, sy, 0));
	while (!q.empty()) {
		const Node &u = q.front();
		for (int i = 0; i < 4; i++) {
			int x1 = u.x + detla[i][0], y1 = u.y + detla[i][1];
			if (x1 < 1 || x1 > n || y1 < 1 || y1 > m) { continue; }
			if (!G[x1][y1]) { continue; }
			if (f[x1][y1][u.fc] > f[u.x][u.y][u.fc] + 1) {
				f[x1][y1][u.fc] = f[u.x][u.y][u.fc] + 1;
				q.push(Node(x1, y1, u.fc));
			}
		}
		if (u.fc < 4 && G[gax(u.x)][gax(u.y)] && f[gax(u.x)][gax(u.y)][u.fc + 1] > f[u.x][u.y][u.fc] + 1) {
			f[gax(u.x)][gax(u.y)][u.fc + 1] = f[u.x][u.y][u.fc] + 1;
			q.push(Node(gax(u.x), gax(u.y), u.fc + 1));
		}
		q.pop();
	}
	int ans = INF;
	for (int i = 0; i < 5; i++) { ans = min(ans, f[tx][ty][i]); }
	printf("%d\n", ans == INF ? -1 : ans);
}
