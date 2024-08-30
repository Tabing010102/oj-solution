#include <cstdio>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

vector<int> I, R;
unordered_set<int> us;
int n, m;
vector<vector<int>> ans;
int ansL = 0;

bool judge(const int &a, const int &b) {
    int t = 1, tb = b;
    while (tb) { t *= 10; tb /= 10; }
    if (b == 0) { t = 10; }
    int ta = a;
    while (ta) {
        if (ta % t == b) { return true; }
        ta /= 10;
    }
    return false;
}

int main() {
    int t;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) { scanf("%d", &t); I.push_back(t); }
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &t);
        if (us.find(t) == us.end()) {
            us.insert(t);
            R.push_back(t);
        }
    }
    sort(R.begin(), R.end());
    for (const int &r : R) {
        ans.push_back(vector<int>());
        vector<int> &cur = ans[ans.size() - 1]; 
        for (int i = 0; i < I.size(); i++) {
            if (judge(I[i], r)) {
                cur.push_back(i);
                ansL++;
            }
        }
    }
    for (const vector<int> &cur : ans) { if (cur.size() > 0) { ansL++; } }
    printf("%d ", ansL * 2);
    for (int i = 0; i < ans.size(); i++) {
        const vector<int> &cur = ans[i];
        if (cur.size() == 0) { continue; }
        printf("%d %d ", R[i], cur.size());
        for (const int &b : cur) { printf("%d %d ", b, I[b]); }
//        printf("\n");
    }
    return 0;
}
