#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000 + 10;

struct Edge {
    int from, to;
    int dist;
    Edge(int f, int t, int d) : from(f), to(t), dist(d) {}
};

int n;
int fa[MAXN];
vector<Edge> edges;

class Solution {
public:
    static bool cmp(const Edge &a, const Edge &b) { return a.dist < b.dist; }
    int getDist(int p1, int p2, vector<vector<int>>& points) {
        return abs(points[p1][0] - points[p2][0]) + abs(points[p1][1] - points[p2][1]);
    }
    int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
    int minCostConnectPoints(vector<vector<int>>& points) {
        n = points.size();
        for (int i = 0; i < n; i++) { fa[i] = i; }
        edges.clear();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int d = getDist(i, j, points);
                edges.push_back(Edge(i, j, d));
            }
        }
        sort(edges.begin(), edges.end(), cmp);
        int ans = 0;
        for (auto it = edges.begin(); it != edges.end(); it++) {
            Edge &e = *it;
            if (find(e.from) == find(e.to)) { continue; }
            else {
                fa[find(e.to)] = find(e.from);
                ans += e.dist;
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
//    vector<int> x1 = { 0, 0 };
//    vector<int> x2 = { 2, 2 };
//    vector<int> x3 = { 3, 10 };
//    vector<int> x4 = { 5, 2 };
//    vector<int> x5 = { 7, 0 };
//    vector<vector<int>> x = { x1, x2, x3, x4, x5 };
    vector<int> x1 = { 0, 0 };
    vector<int> x2 = { 1, 1 };
    vector<int> x3 = { 1, 0 };
    vector<int> x4 = { -1, 1 };
    vector<vector<int>> x = { x1, x2, x3, x4 };
    auto ans = s.minCostConnectPoints(x);
    cout << ans << endl;
    return 0;
}
