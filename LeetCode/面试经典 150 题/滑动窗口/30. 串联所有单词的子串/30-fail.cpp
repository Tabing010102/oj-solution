#include <bits/stdc++.h>

using namespace std;

#define CURL (l * ws + os)
#define CURLP ((l + 1) * ws + os)
#define CURR (r * ws + os)
#define CURRP ((r + 1) * ws + os)

// assume words do not contain duplicated word
class Solution {
public:
    const int MAXS = 1e4 + 10;
    const int MAXW = 5000 + 10;
    vector<int> findSubstring(string s, vector<string>& words) {
        int n = s.size();
        int ws = words[0].size();
        int wc = words.size();
        if (ws * wc > n) { return vector<int>(); }
        vector<int> ans;
        // pre process
        map<string, int> ms;
        for (int i = 0; i < wc; i++) { ms[words[i]] = i; }
        int d[MAXS];
        for (int i = 0; i <= n - ws; i++) {
            string cs = s.substr(i, ws);
            if (ms.find(cs) != ms.end()) { d[i] = ms[cs]; }
            else { d[i] = -1; }
        }
        // work
        bool vis[MAXS / ws + 10];
        // ws groups
        for (int os = 0; os < ws; os++) {
            memset(vis, 0, sizeof(vis));
            int l = 0;
            while (CURL + ws < n && d[CURL] == -1) { l++; }
            if (CURL + ws >= n) { continue; }
            int r = l;
            vis[d[CURL]] = true;
            while (CURL + ws < n && CURR < n) {
                // move r
                int orir = r;
                while (CURRP < n && r - l < wc && d[CURRP] != -1 && !vis[d[CURRP]]) { r++; vis[d[CURR]] = true; }
                // -1
                if (r == orir) {
                    while (CURRP < n && d[CURRP] == -1) { r++; }
                    if (r == orir) { break; }
                    l = r;
                    memset(vis, 0, sizeof(vis));
                    vis[d[CURR]] = true;
                }
                if (r - l + 1 == wc) {
                    ans.push_back(CURL);
                    vis[d[CURL]] = false;
                    l++;
                } else {
                    // r is at end
                    if (CURRP >= n) { break; }
                    if (d[CURR] == d[CURRP]) {
                        int ord = d[CURR];
                        while (CURRP < n && d[CURRP] == ord) { r++; }
                        memset(vis, 0, sizeof(vis));
                        l = r;
                        vis[d[CURR]] = true;
                    } else {
                        while (vis[d[CURRP]]) { vis[d[CURLP]] = false; l++; }
                        if (d[CURRP] != -1) {
                            r++;
                            vis[d[CURR]] = true;
                        }
                    }
                }
            }
        }
        return ans;
    }
};

int main() {
    vector<string> x = {"word","good","best","word"};
    Solution s;
    auto ans = s.findSubstring("wordgoodgoodgoodbestword", x);
    for (auto x : ans) { cout << x << " "; }
    return 0;
}
