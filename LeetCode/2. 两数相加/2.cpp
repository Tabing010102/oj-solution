#include <bits/stdc++.h>

using namespace std;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    void append(ListNode *ans, ListNode *&l, int c) {
        while (l) {
            int t = l->val + c;
            if (t >= 10) { c = 1; t -= 10; }
            else { c = 0; }
            ans->next = new ListNode(t);
            ans = ans->next;
            l = l->next;
        }
        if (c) { ans->next = new ListNode(c); }
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *vhead = new ListNode();
        ListNode *ans = vhead;
        int c = 0;
        while (true) {
            if (!l1) { append(ans, l2, c); break; }
            else if (!l2) { append(ans, l1, c); break; }
            else {
                int t = l1->val + l2->val + c;
                if (t >= 10) { c = 1; t -= 10; }
                else { c = 0; }
                ans->next = new ListNode(t);
                ans = ans->next;
                l1 = l1->next; l2 = l2->next;
            }
        }
        ans = vhead->next;
        delete vhead;
        return ans;
    }
};

int main() {
    Solution s;
    auto ans = s.addTwoNumbers(new ListNode(5), new ListNode(5));
    while (ans) {
        printf("%d ", ans->val);
        ans = ans->next;
    }
    return 0;
}
