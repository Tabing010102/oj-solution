#include <bits/stdc++.h>

using namespace std; 

class Solution {
public:
	struct Node {
		int n, val;
		Node(int n, int val) : n(n), val(val) {}
		bool operator < (const Node &rhs) const { return this->n < rhs.n; }
	};
    vector<int> topKFrequent(vector<int>& nums, int k) {
		unordered_map<int, int> m;
		for (auto it = nums.begin(); it != nums.end(); it++) {
			if (m.find(*it) == m.end()) { m[*it] = 1; }
			else { m[*it]++; }
		}
		priority_queue<Node> pq;
		for (auto it = m.begin(); it != m.end(); it++) {
			Node node = Node(it->second, it->first);
			pq.push(node);
		}
		vector<int> ans;
		for (int i = 0; i < k; i++) {
			ans.push_back(pq.top().val);
			pq.pop();
		}
		return ans;
    }
};

int main() {
	Solution s;
	vector<int> x = { 1,1,1,2,2,3 };
	auto ans = s.topKFrequent(x, 2);
	for (auto v : ans) { cout << v << " "; }
	cout << endl;
	return 0;
}
