#include <bits/stdc++.h>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

struct Node2 {
    Node *fa, *cnt;
    Node2(Node *a, Node *b) : fa(a), cnt(b) {}
};

class Solution {
public:
    void findNext(Node *uc, Node *c) {
        if (c == uc->left && uc->right != nullptr) { c->next = uc->right; }
        else {
            if (c == uc->left || c == uc->right) { uc = uc->next; }
            while (uc != nullptr) {
                if (uc->left != nullptr) { c->next = uc->left; break; }
                if (uc->right != nullptr) { c->next = uc->right; break; }
                uc = uc->next;
            }
        }
    }
    Node* connect(Node* root) {
        queue<Node2> q;
        q.push(Node2(nullptr, root));
        while (!q.empty()) {
            Node2 cnt2 = q.front(); q.pop();
            Node *fa = cnt2.fa;
            Node *cnt = cnt2.cnt;
            if (cnt2.cnt == nullptr) { continue; }
            if (fa != nullptr) { findNext(fa, cnt); }
            if (cnt2.cnt->left) { q.push(Node2(cnt2.cnt, cnt2.cnt->left)); }
            if (cnt2.cnt->right) { q.push(Node2(cnt2.cnt, cnt2.cnt->right)); }
        }
        return root;
    }
};

int main() {
    Solution s;
    return 0;
}
