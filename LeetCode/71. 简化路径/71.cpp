#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
    	path += "/";
		int n = path.size();
		int p = 1;
		deque<string> q;
		while (p < n) {
			int op = p;
			while (p < n && path[p] != '/') p++;
			if (p == op) { p++; continue; }
			else if (p - op == 1 && path[p - 1] == '.') { p++; continue; }
			else if (p - op == 2 && path[p - 1] == '.' && path[p - 2] == '.') {
				if (!q.empty()) {
					printf("pop queue = %s\n", q.back().c_str());
					q.pop_back();
				}
				p++;
			} else {
				if ( p - op >= 1 ) {
					printf("push_front queue = %s\n", path.substr(op, p - op).c_str());
					q.push_back(path.substr(op, p - op));
				}
				p++;
			}
		}
		string ans = "/";
		while (!q.empty()) {
			ans += q.front();
			q.pop_front();
			if (!q.empty()) ans += "/";
		}
		return ans;
    }
};

int main() {
	Solution s;
//	cout << s.simplifyPath("/home//foo/") << endl;
//	cout << s.simplifyPath("/a/./b/../../c/") << endl;
//	cout << s.simplifyPath("/../") << endl;
//	cout << s.simplifyPath("/home/") << endl;
	cout << s.simplifyPath("/a//b////c/d//././/..") << endl;
	return 0;
}
