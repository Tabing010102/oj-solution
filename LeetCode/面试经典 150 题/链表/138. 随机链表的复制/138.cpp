#include <bits/stdc++.h>

using namespace std;


// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node *vhead = new Node(0);
        Node *cnt = head;
        Node *last = vhead;
        unordered_map<Node *, Node *> m;
        while (cnt != nullptr) {
            Node *t = new Node(cnt->val);
            m[cnt] = t;
            last->next = t;
            last = t;
            cnt = cnt->next;
        }
        cnt = head;
        Node *ncnt = vhead->next;
        while (ncnt != nullptr) {
            ncnt->random = m[cnt->random];
            ncnt = ncnt->next;
            cnt = cnt->next;
        }
        Node *ans = vhead->next;
        delete vhead;
        return ans;
    }
};

int main() {
    return 0;
}
