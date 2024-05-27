#include <bits/stdc++.h>

using namespace std; 

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

struct Node2 {
    Node *fa, *curr;
    Node2(Node *a, Node *b) : fa(a), curr(b) {}
};

class Solution {
public:
    Node* cloneGraph(Node* node) {
        queue<Node2> q;
        q.push(Node2(nullptr, node));
        bool first = true;
        Node *ans = nullptr;
        unordered_set<Node *> us;
        unordered_map<Node *, Node *> um;
        while (!q.empty()) {
            Node2 c = q.front(); q.pop();
            if (!c.curr) { continue; }
            Node *nc;
            if (um.find(c.curr) != um.end()) { nc = um[c.curr]; }
            else { nc = new Node(c.curr->val); um[c.curr] = nc; }
            if (first) { ans = nc; first = false; }
            if (c.fa) {
                c.fa->neighbors.push_back(nc);
                nc->neighbors.push_back(c.fa);
            }
            us.insert(c.curr);
            for (auto x : c.curr->neighbors) {
                if (us.find(x) != us.end()) { continue; }
                q.push(Node2(nc, x));
            }
        }
        return ans;
    }
};

int main() {
    Node *x1 = new Node(1);
    Node *x2 = new Node(2);
    Node *x3 = new Node(3);
    Node *x4 = new Node(4);
    x1->neighbors.push_back(x2);
    x1->neighbors.push_back(x4);
    x2->neighbors.push_back(x1);
    x2->neighbors.push_back(x3);
    x3->neighbors.push_back(x2);
    x3->neighbors.push_back(x4);
    x4->neighbors.push_back(x1);
    x4->neighbors.push_back(x3);
    Solution s;
    auto ans = s.cloneGraph(x1);
    return 0;
}
