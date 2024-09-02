#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 1000 + 10;

char s[MAXN];
int n;

inline bool isDigit(const char &c) { return c >= '0' && c <= '9'; }
inline bool isUpper(const char &c) { return c >= 'A' && c <= 'Z'; }
inline bool isLower(const char &c) { return c >= 'a' && c <= 'z'; }

char encode(const char &c) {
    if (isDigit(c)) { return c == '9' ? '0' : c + 1; }
    else if (isUpper(c)) { return c == 'Z' ? 'a' : c - 'A' + 'a' + 1; }
    else if (isLower(c)) { return c == 'z' ? 'A' : c - 'a' + 'A' + 1; }
    else { return c; }
}
char decode(const char &c) {
    if (isDigit(c)) { return c == '0' ? '9' : c - 1; }
    else if (isUpper(c)) { return c == 'A' ? 'z' : c - 'A' + 'a' - 1; }
    else if (isLower(c)) { return c == 'a' ? 'Z' : c - 'a' + 'A' - 1; }
    else { return c; }
}

int main() {
    scanf("%s", s);
    n = strlen(s);
    for (int i = 0; i < n; i++) { s[i] = encode(s[i]); }
    printf("%s\n", s);
    scanf("%s", s);
    n = strlen(s);
    for (int i = 0; i < n; i++) { s[i] = decode(s[i]); }
    printf("%s\n", s);
    return 0;
}
