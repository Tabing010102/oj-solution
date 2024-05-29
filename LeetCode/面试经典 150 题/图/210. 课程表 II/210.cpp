#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2000 + 10;

struct Edge {
    int from, to; 
    double dist;
    Edge(int a, int b, double c) : from(a), to(b), dist(c) {}
};

vector<int> G[MAXN];
vector<Edge> edges;
int in[MAXN];

class Solution {
public:
    void addEdge(int from, int to, double dist) {
        int esize = edges.size();
        edges.push_back(Edge(from, to, dist));
        G[from].push_back(esize);
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        memset(in, 0, sizeof(in));
        for (int i = 0; i < numCourses; i++) { G[i].clear(); }
        edges.clear();
        for (auto e : prerequisites) { addEdge(e[1], e[0], 1); in[e[0]]++; }
        // topo
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (in[i] == 0) {
                q.push(i);
            }
        }
        vector<int> ans;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            ans.push_back(u);
            for (auto ei : G[u]) {
                Edge &e = edges[ei];
                if (--in[e.to] == 0) {
                    q.push(e.to);
                }
            }
        }
        return ans.size() == numCourses ? ans : vector<int>();
    }
};

int main() {
    Solution s;
    return 0;
}
