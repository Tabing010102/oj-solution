#include <iostream>
#include <string>
#include <map>
#include <queue>

using namespace std;

map<pair<string, int>, int> um;
queue<pair<string, int>> q;
int qL = 0;

inline int min(const int &a, const int &b) { return a < b ? a : b; }
inline int max(const int &a, const int &b) { return a > b ? a : b; }

pair<string, int> getPair(const string &s, const int &ln) {
	int p = s.rfind("\\");
	return pair<string, int>(s.substr(max(s.length() - 16, p + 1)), ln);
}

int main() {
	string s;
	int ln;
	while (cin >> s >> ln) {
		pair<string, int> p = getPair(s, ln);
		if (um.find(p) != um.end()) { um[p]++; }
		else {
			if (qL >= 8) { q.pop(); qL--; }
			q.push(p); qL++;
			um[p] = 1;
		}
	}
	while (!q.empty()) {
		const pair<string, int> &a = q.front();
		printf("%s %d %d\n", a.first.c_str(), a.second, um[a]);
		q.pop();
	}
	return 0;
}
