#include <bits/stdc++.h>

using namespace std;

#define CNTP (p * ws + os)
#define CNTPP ((p + 1) * ws + os)

// assume words do not contain duplicated word
class Solution {
public:
    const int MAXS = 1e4 + 10;
    const int MAXW = 5000 + 10;
    const bool DEBUG = 0;
    vector<int> findSubstring(string s, vector<string>& words) {
        int n = s.size();
        int ws = words[0].size();
        int wc = words.size();
        if (ws * wc > n) { return vector<int>(); }
        vector<int> ans;
        // pre process
        map<string, int> ms;
        for (int i = 0; i < wc; i++) {
            ms[words[i]] = i;
            if (DEBUG) { printf("ms[%s] = %d\n", words[i].c_str(), i); }
        }
        int d[MAXS];
        for (int i = 0; i <= n - ws; i++) {
            string cs = s.substr(i, ws);
            if (ms.find(cs) != ms.end()) { d[i] = ms[cs]; }
            else { d[i] = -1; }
        }
        for (int i = n - 1; i > n - ws; i--) { d[i] = -1; }
        if (DEBUG) {
            printf("d: ");
            for (int i = 0; i < n; i++) { printf("%d ", d[i]); }
            printf("\n");
        }
        // work
        bool vis[MAXW];
        deque<int> q;
        // ws groups
        for (int os = 0; os < ws; os++) {
            q.clear();
            memset(vis, 0, sizeof(vis));
            int p = 0;
            while (CNTP < n) {
                int cnt = d[CNTP];
                if (q.size() == wc) {
                    ans.push_back(q.front());
                    vis[d[q.front()]] = false; q.pop_front();
                }
                if (cnt == -1) {
                    if (DEBUG) { printf("os=%d, p=%d, cnt=%d, clear vis\n", os, p, cnt); }
                    q.clear();
                    memset(vis, 0, sizeof(vis));
                } else {
                    while (!q.empty() && vis[cnt]) {
                        if (DEBUG) {
                            printf("os=%d, p=%d, cnt=%d, ", os, p, cnt);
                            printf("remove q.front()=%d, ", q.front());
                            printf("vis idx d[q.front()]=%d\n", d[q.front()]);
                        }
                        vis[d[q.front()]] = false; q.pop_front();
                    }
                    if (DEBUG && q.empty() && vis[cnt]) { printf("E: os=%d, p=%d, cnt=%d\n", os, p, cnt); }
                }
                while (CNTP < n && d[CNTP] == -1) { p++; }
                if (CNTP < n && d[CNTP] != -1) {
                    vis[d[CNTP]] = true;
                    q.push_back(CNTP);
                    p++;
                }
            }
        }
        return ans;
    }
};

int main() {
//    vector<string> x = {"word","good","best","word"};
//    Solution s;
//    auto ans = s.findSubstring("wordgoodgoodgoodbestword", x);
//    vector<string> x = {"bar","foo","the"};
//    Solution s;
//    auto ans = s.findSubstring("barfoofoobarthefoobarman", x);
    vector<string> x = {"word","good","best","good"};
    Solution s;
    auto ans = s.findSubstring("wordgoodgoodgoodbestword", x);
    for (auto x : ans) { cout << x << " "; }
    return 0;
}
