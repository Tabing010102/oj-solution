#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 1000 + 10;

struct CC {
    char c;
    int p;
    CC(const char c, const int p) : c(c), p(p) {}
    CC() {}
};

char s[MAXN];
int n, m;
CC cc[MAXN];

inline bool isUpper(const char &c) { return c >= 'A' && c <= 'Z'; }
inline bool isLower(const char &c) { return c >= 'a' && c <= 'z'; }
inline char toLower(const char &c) { return isLower(c) ? c : c - 'A' + 'a'; }

bool cmp(const CC &a, const CC &b) {
    if (toLower(a.c) == toLower(b.c)) { return a.p < b.p; }
    else { return toLower(a.c) < toLower(b.c); }
}

void gets1(char *s) {
    char c;
    int p = 0;
    while ((c = getchar()) != EOF) {
        if (c == '\n') { break; }
        s[p++] = c;
    }
    s[p++] = '\0';
}

int main() {
    gets1(s);
    n = strlen(s);
    for (int i = 0; i < n; i++) {
        if (isUpper(s[i]) || isLower(s[i])) {
            cc[m++] = CC(s[i], i);
        }
    }
    sort(cc, cc + m, cmp);
    int p = 0;
    for (int i = 0; i < n; i++) {
        if (isUpper(s[i]) || isLower(s[i])) {
            putchar(cc[p++].c);
        } else {
            putchar(s[i]);
        }
    }
    return 0;
}
