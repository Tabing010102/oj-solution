#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        string &s = path;
        int n = s.size();
        int p = 0;
        deque<string> dq;
        while (p < n) {
            while (p < n && s[p] == '/') { p++; }
            while (p < n && s[p] != '/') {
                if (s[p] == '.') {
                    int p1 = p;
                    while (p < n && s[p] == '.') { p++; }
                    if (p - p1 == 1 && (p == n || (p < n && s[p] == '/'))) { break; }
                    else if (p - p1 == 2 && (p == n || (p < n && s[p] == '/'))) {
                        if (!dq.empty()) {
                            dq.pop_back();
                        }
                    } else {
                        while (p < n && s[p] != '/') { p++; }
                        dq.push_back(s.substr(p1, p - p1));
                    }
                } else {
                    int p1 = p;
                    while (p < n && s[p] != '/') { p++; }
                    dq.push_back(s.substr(p1, p - p1));
                }
            }
        }
        string ans = "";
        while (!dq.empty()) {
            ans += "/" + dq.front();
            dq.pop_front();
        }
        if (ans == "") { ans = "/"; }
        return ans;
    }
};

int main() {
    Solution s;
//    auto ans = s.simplifyPath("/../");
    auto ans = s.simplifyPath("/home//foo/.////");
    cout << ans;
    return 0;
}
