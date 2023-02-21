#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <queue>

using namespace std;

const int MAXN = 10 + 2;
const int D[][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

int n, m;
int G[MAXN][MAXN];
bool vis[MAXN][MAXN];
int tot = 0, tar, cnt = 0;
int ans = 0x7fffffff;

inline int min(const int &a, const int &b) { return a < b ? a : b; }

bool vis2[MAXN][MAXN];
void dfs2(int x, int y) {
	vis2[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int tx = x + D[i][0];
		int ty = y + D[i][1];
		if (tx < 0 || tx >= n || ty < 0 || ty >= m) continue;
		if (vis[tx][ty] == true) continue;
		if (vis2[tx][ty] == true) continue;
		dfs2(tx, ty);
	}
}
void print_vis() {
	printf("print vis\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) printf("%d ", vis[i][j]);
		printf("\n");
	}
}
void print_vis2() {
	printf("print vis2\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) printf("%d ", vis2[i][j]);
		printf("\n");
	}
}
bool can2part() {
	memset(vis2, 0, sizeof(vis2));
	bool done = false;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (done == false && vis[i][j] == false) {
//				printf("check vis[%d][%d]\n", i, j);
				dfs2(i, j);
				done = true;
				break;
			}
//	print_vis(); print_vis2();
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (vis[i][j] == false && vis2[i][j] == false)
				return false;
	return true;
}

void calc_ans() {
	int tans = 1;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (vis[i][j]) tans++;
	ans = min(ans, tans);
}

void dfs(int x, int y) {
	if (cnt + G[x][y] == tar) {
		vis[x][y] = true;
		if (can2part() == false) return;
		vis[x][y] = false;
		calc_ans();
		return;
	}
	if (cnt + G[x][y] > tar) return;
	cnt += G[x][y]; vis[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int tx = x + D[i][0];
		int ty = y + D[i][1];
		if (tx < 0 || tx >= n || ty < 0 || ty >= m) continue;
		if (vis[tx][ty]) continue;
		dfs(tx, ty);
	}
	cnt -= G[x][y]; vis[x][y] = false;
}

int main() {
	scanf("%d%d", &m ,&n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			scanf("%d", &G[i][j]);
			tot += G[i][j];
		}
	if (tot % 2 == 1) {
		printf("0\n");
		exit(0);
	}
	memset(vis, 0, sizeof(vis));
	tar = tot / 2;
	dfs(0, 0);
	printf("%d\n", ans != 0x7fffffff ? ans : 0);
	return 0;
}
