#include <cstdio>
#include <iostream>

using namespace std;

typedef long long LL;

const int MAXN = 200000 + 10;
int n, d[MAXN];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &d[i]);
	LL ans = 0;
	LL t = 0;
	for (int i = 0; i < n; i++) {
		ans += d[i] * t;
		t += d[i];
	}
	cout << ans;
	return 0;
}
