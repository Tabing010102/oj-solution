#include <bits/stdc++.h>

using namespace std;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head || !(head->next)) { return false; }
        ListNode* p1, *p2;
        p1 = head;
        p2 = head;
        do {
            p1 = p1->next;
            p2 = p2->next;
            if (p2) { p2 = p2->next; }
            if (p1 == p2) { return true; }
        } while (p2 != nullptr);
        return false;
    }
};

int main() {
    return 0;
}
