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
    void appendRest(ListNode *ans, ListNode *l) {
        while (l) {
            ans->next = new ListNode(l->val);
            ans = ans->next;
            l = l->next;
        }
    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *vhead = new ListNode();
        ListNode *ans = vhead;
        while (true) {
            if (!list1) { appendRest(ans, list2); break; }
            else if (!list2) { appendRest(ans, list1); break; }
            else {
                int t;
                if (list1->val > list2->val) {
                    t = list2->val;
                    list2 = list2->next;
                } else {
                    t = list1->val;
                    list1 = list1->next;
                }
                ans->next = new ListNode(t);
                ans = ans->next;
            }
        }
        ans = vhead->next;
        delete vhead;
        return ans;
    }
};

int main() {
    Solution s;
    auto ans = s.mergeTwoLists(new ListNode(5), new ListNode(5));
    while (ans) {
        printf("%d ", ans->val);
        ans = ans->next;
    }
    return 0;
}
