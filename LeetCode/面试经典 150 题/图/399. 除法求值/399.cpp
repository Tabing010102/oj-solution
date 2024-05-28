#include <bits/stdc++.h>

using namespace std; 

const int MAXN = 20 + 10;

struct Edge {
    int from, to; 
    double dist;
    Edge(int a, int b, double c) : from(a), to(b), dist(c) {}
};

vector<int> G[MAXN];
vector<Edge> edges;
bool vis[MAXN];
double d[MAXN];

class Solution {
public:
    void addEdge(int from, int to, double dist) {
        int esize = edges.size();
        edges.push_back(Edge(from, to, dist));
        G[from].push_back(esize);
    }
    double getDist(int from, int to) {
        memset(vis, 0, sizeof(vis));
        memset(d, 0, sizeof(d));
        queue<int> q;
        q.push(from);
        vis[from] = true;
        d[from] = 1.0;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            if (u == to) { return d[u] == 0 ? -1.0 : d[u]; }
            for (auto ei : G[u]) {
                Edge &e = edges[ei];
                if (vis[e.to]) { continue; }
                vis[e.to] = true;
                d[e.to] = d[u] * e.dist;
                q.push(e.to);
            }
        }
        return -1.0;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        for (int i = 0; i < MAXN; i++) { G[i].clear(); }
        edges.clear();
        unordered_map<string, int> n2ium;
        for (int i = 0; i < equations.size(); i++) {
            string s1 = equations[i][0], s2 = equations[i][1];
            double d = values[i];
            int i1, i2;
            if (n2ium.find(s1) != n2ium.end()) { i1 = n2ium[s1]; }
            else { i1 = n2ium.size(); n2ium[s1] = i1; }
            if (n2ium.find(s2) != n2ium.end()) { i2 = n2ium[s2]; }
            else { i2 = n2ium.size(); n2ium[s2] = i2; }
            addEdge(i1, i2, 1.0 / d);
            addEdge(i2, i1, d);
        }
        vector<double> ans;
        for (auto query : queries) {
            string s1 = query[0], s2 = query[1];
            int i1, i2;
            if (n2ium.find(s1) != n2ium.end()) { i1 = n2ium[s1]; }
            else { ans.push_back(-1.0); continue; }
            if (n2ium.find(s2) != n2ium.end()) { i2 = n2ium[s2]; }
            else { ans.push_back(-1.0); continue; }
            double dist = getDist(i2, i1);
            ans.push_back(dist);
        }
        return ans;
    }
};

int main() {
    vector<vector<string>> x1 = {vector<string>{"a", "b"}, vector<string>{"b", "c"}};
    vector<double> x2 = { 2.0, 3.0 };
    vector<vector<string>> q = {
        vector<string>{"a", "c"},
        vector<string>{"b", "a"},
        vector<string>{"a", "e"},
        vector<string>{"a", "a"},
        vector<string>{"x", "x"},
    };
    Solution s;
    auto ans = s.calcEquation(x1, x2, q);
    for (auto x : ans) { cout << x << endl; }
    return 0;
}
