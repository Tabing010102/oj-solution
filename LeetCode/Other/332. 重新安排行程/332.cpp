/*  FULL OF BULLSHIT  */

#include <bits/stdc++.h>

using namespace std;

struct Node {
	char s[3];
	bool operator < (const Node &rhs) const {
		for (int i = 0; i < 3; i++) {
			if (s[i] != rhs.s[i]) {
				return s[i] < rhs.s[i];
			}
		}
		return s[2] < rhs.s[2];
	}
	bool operator == (const Node &rhs) const {
		for (int i = 0; i < 3; i++) {
			if (s[i] != rhs.s[i]) {
				return false;
			}
		}
		return true;
	}
	Node (string ss) {
		this->s[0] = (char)ss[0];
		this->s[1] = (char)ss[1];
		this->s[2] = (char)ss[2];
	}
	const string toString() const {
		string ss;
		ss.push_back(this->s[0]);
		ss.push_back(this->s[1]);
		ss.push_back(this->s[2]);
		return ss;
	}
};

struct Node2 {
	Node from, to;
	Node2(Node f, Node t) : from(f), to(t) {}
	bool operator == (const Node2 &rhs) const {
		return (this->from) == (rhs.from) && (this->to) == (rhs.to);
	}
};

namespace std {
	template<>
	struct hash<Node> {
	    inline size_t operator() (const Node& x) const {
	        size_t value = (int)x.s[0] + (int)x.s[1] * 26 + (int)x.s[2] * 26 * 26;
	        return value;
	    }
	};
	template<>
	struct hash<Node2> {
	    inline size_t operator() (const Node2& x) const {
	        size_t value = (int)x.from.s[0] * 17576 + (int)x.from.s[1] * 17576 * 26 + (int)x.from.s[2] * 17576 * 26 * 26;
	        value += (int)x.to.s[0] + (int)x.to.s[1] * 26 + (int)x.to.s[2] * 26 * 26;
	        return value;
	    }
	};
}

vector<string> ans;
unordered_map<Node, vector<Node>> G;
unordered_map<Node, int> vis;
unordered_map<Node2, int> vis2;
bool done;
int n;

class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
		vector<vector<string>> &oe = tickets;
		ans.clear();
		G.clear();
		vis.clear();
		vis2.clear();
		done = false;
		
		for (auto a : oe) {
			Node a0 = Node(a[0]), a1 = Node(a[1]);
			vis2[Node2(a0, a1)]++;
//			printf("vis2[%s,%s] = %d\n", a0.toString().c_str(), a1.toString().c_str(), vis2[Node2(a0, a1)]); 
			if (G.find(a0) == G.end()) { G[a0] = vector<Node>(); }
			G[a0].push_back(a1);
			vis[a1]++;
		}
//		for (auto a : vis) {
//			printf("vis[%s] = %d\n", a.first.toString().c_str(), a.second); 
//		}
//		for (auto a : vis2) {
//			printf("vis2[%s,%s] = %d\n", a.first.from.toString().c_str(), a.first.to.toString().c_str(), a.second); 
//		}
		n = oe.size();
		ans.resize(n + 1);
		for (auto it = G.begin(); it != G.end(); it++) {
			sort(it->second.begin(), it->second.end());
		}
		ans[0] = "JFK";
		dfs(Node("JFK"), 0);
		return ans;
    }
    void dfs(Node cur, int dep) {
    	if (dep == n) {
			done = true;
//			printf("cur = %s, dep = %d, done = true\n", cur.toString().c_str(), dep, done);
			return;
		}
    	if (done) { return; }
    	if (vis[cur] < 0) { return; }
    	Node last = Node("000"); 
    	for (auto it = G[cur].begin(); it != G[cur].end() && !done; it++) {
    		Node &to = *it;
    		if (last == to) { continue; }
    		Node2 n2 = Node2(cur, to);
    		if (vis[to] <= 0) { continue; }
    		if (vis2[n2] <= 0) { continue; }
    		vis[to]--;
    		vis2[n2]--;
//    		printf("vis[%s] = %d\n", to.toString().c_str(), vis[to]); 
//    		printf("ans[%d] = %s\n", dep + 1, to.toString().c_str());
    		ans[dep + 1] = to.toString().c_str();
    		dfs(to, dep + 1);
    		vis[to]++;
    		vis2[n2]++;
    		last = to;
//    		printf("vis[%s] = %d\n", to.toString().c_str(), vis[to]); 
    	}
    }
};

int main() {
	Solution s;
	vector<vector<string>> a = vector<vector<string>>();
	a.push_back(vector<string>{"JFK","SFO"});
	a.push_back(vector<string>{"JFK","ATL"});
	a.push_back(vector<string>{"SFO","ATL"});
	a.push_back(vector<string>{"ATL","JFK"});
	a.push_back(vector<string>{"ATL","SFO"});
	auto ans = s.findItinerary(a);
	for (auto a : ans) { cout << a << " "; }
	return 0;
}
