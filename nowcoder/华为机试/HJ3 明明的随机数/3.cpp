#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 500 + 10;

bool vis[MAXN];
int n;

int main() {
	scanf("%d", &n);
	memset(vis, 0, sizeof(vis));
	int t;
	for (int i = 0; i < n; i++) {
		scanf("%d", &t);
		vis[t] = true;
	}
	for (int i = 1; i <= 500; i++) {
		if (vis[i]) {
			printf("%d\n", i);
		}
	}
	return 0;
}
