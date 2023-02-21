#include <bits/stdc++.h>

const int MAXN = 3;
const int D[][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

int n, m;

bool vis[MAXN][MAXN];
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

int main() {
	n = 3; m = 3;
	memset(vis, 0, sizeof(vis));
	memset(vis2, 0, sizeof(vis2));
	vis[0][0] = 1;
	vis[0][1] = 1;
	vis[1][1] = 1;
	vis[1][2] = 1;
	print_vis();
	dfs2(0, 2);
	print_vis2();
}
