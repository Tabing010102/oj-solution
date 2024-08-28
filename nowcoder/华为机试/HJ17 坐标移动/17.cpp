#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 10000 + 10;

char s[MAXN];
int n;
int x = 0, y = 0;

inline bool isDirCharValid(const char &c) { return c == 'W' || c == 'A' || c == 'S' || c == 'D'; }
inline bool isDigit(const char &c) { return c >= '0' && c <= '9'; }
int getNum(int p, int w) {
	for (int i = 0; i < w; i++) {
		if (!isDigit(s[p + i])) {
			return -1;
		}
	}
	if (w == 1) { return s[p] - '0'; }
	else if (w == 2) { return (s[p] - '0') * 10 + (s[p + 1] - '0'); }
	else { return -1; }
}

void move(const char &d, const int &l) {
	if (d == 'W') { y += l; }
	else if (d == 'A') { x -= l; }
	else if (d == 'S') { y -= l; }
	else { x += l; }
}

int main() {
	scanf("%s", s);
	int n = strlen(s);
	int p = 0, last = 0, bp = 0;
	while (p < n) {
		bp = 0;
		while (p < n && s[p] != ';') { p++; bp++; }
		if (!(bp < 2 || bp > 3 || !isDirCharValid(s[last]))) {
			int t = getNum(last + 1, bp - 1);
			move(s[last], t < 0 ? 0 : t);
		}
		while (p < n && s[p] == ';') { p++; }
		last = p;
	}
	printf("%d,%d\n", x, y);
	return 0;
}
