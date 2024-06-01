#include <bits/stdc++.h>

using namespace std;

const int MAXN = 10 + 5;

int n;
bool vis[MAXN];
int d[MAXN];

class Solution {
public:
    string getGene(int idx, string &startGene, vector<string>& bank) {
        if (idx == 0) { return startGene; }
        else { return bank[idx - 1]; } 
    }
    bool canTrans(const string &a, const string &b) {
        int diff = 0;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] != b[i]) { diff++; }
            if (diff > 1) { return false; }
        }
        return diff == 1;
    }
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        n = bank.size() + 1;
        memset(vis, 0, sizeof(vis));
        memset(d, -1, sizeof(d));
        int eidx = find(bank.begin(), bank.end(), endGene) == bank.end()
                        ? -1
                        : find(bank.begin(), bank.end(), endGene) - bank.begin() + 1;
        if (eidx == -1) { return -1; }
        queue<int> q;
        q.push(0);
        vis[0] = true;
        d[0] = 0;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            string ux = getGene(u, startGene, bank);
            for (int i = 1; i < n; i++) {
                if (!canTrans(ux, getGene(i, startGene, bank))) { continue; }
                if (d[i] == -1 || d[i] > d[u] + 1) {
                    d[i] = d[u] + 1;
                    q.push(i);
                }
            }
        }
        return d[eidx];
    }
};

int main() {
    Solution s;
    return 0;
}
