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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr || head->next == nullptr) { return head; }
        
        ListNode *vhead = new ListNode(0, head);
        
        ListNode *last2 = vhead;
        ListNode *last = head;
        ListNode *cnt = head->next;
        while (cnt != nullptr) {
            if (last->val == cnt->val) {
                int v = cnt->val;
                ListNode *ccnt = last;
                while (ccnt != nullptr && ccnt->val == v) {
                    ListNode *oNext = ccnt->next;
                    delete ccnt;
                    ccnt = oNext;
                }
                last2->next = ccnt;
                if (ccnt != nullptr) {
                    last = ccnt;
                    cnt = ccnt->next;
                } else {
                    break;
                }
            } else {
                last2 = last;
                last = cnt;
                cnt = cnt->next;
            }
        }
        
        ListNode *ans = vhead->next;
        delete vhead;
        return ans;
    }
};

int main() {
    Solution s;
    ListNode *x = new ListNode(
        1,
        new ListNode(
            2,
            new ListNode(
                3,
                new ListNode(
                    4,
                    new ListNode(4)
                )
            )
        )
    );
    auto ans = s.deleteDuplicates(x);
    while (ans != nullptr) {
        printf("%d ", ans->val);
        ans = ans->next;
    }
    return 0;
}
