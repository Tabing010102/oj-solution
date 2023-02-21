#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 100 + 10;

int n;
int d[MAXN * MAXN];
int ans_miss, ans_dup;

int main() {
	scanf("%d", &n);
	n = 0;
	while (scanf("%d", &d[n]) == 1) n++;
	sort(d, d+n);
	int last = d[0];
	for (int i = 1; i < n; i++) {
		int &cnt = d[i];
		if (cnt == last) ans_dup = cnt;
		if (cnt - last == 2) ans_miss = last + 1;
		last = cnt;
	}
	printf("%d %d\n", ans_miss, ans_dup);
	return 0;
}
