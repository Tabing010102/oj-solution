#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const int MAXN = 200 + 10;

struct Node {
    string name;
    int score;
    int idx;
};

Node d[MAXN];
int n, st;

bool cmpAsc(const Node &a, const Node &b) {
    if (a.score == b.score) { return a.idx < b.idx; }
    else { return a.score < b.score; }
}

bool cmpDesc(const Node &a, const Node &b) {
    if (a.score == b.score) { return a.idx < b.idx; }
    else { return a.score > b.score; }
}

int main() {
    scanf("%d%d", &n, &st);
    string ts;
    int tsc;
    for (int i = 0; i < n; i++) {
        cin >> ts >> tsc;
        d[i].name = ts;
        d[i].score = tsc;
        d[i].idx = i;
    }
    if (st == 0) { sort(d, d + n, cmpDesc); }
    else { sort(d, d + n, cmpAsc); }
    for (int i = 0; i < n; i++) { cout << d[i].name << " " << d[i].score << endl; }
    return 0;
}
