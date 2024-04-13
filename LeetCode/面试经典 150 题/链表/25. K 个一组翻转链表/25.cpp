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
    void reverseK(ListNode *head, int count, ListNode *pre, ListNode *post) {
        ListNode *cnt = head->next;
        ListNode *last = head;
        for (int i = 0; i < count - 1; i++) {
            ListNode *oNext = cnt->next;
            cnt->next = last;
            last = cnt;
            cnt = oNext;
        }
        pre->next->next = post;
        pre->next = last;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k == 1) { return head; }
        ListNode *cnt = head;
        ListNode *vhead = new ListNode(0, head);
        ListNode *last = vhead;
        while (cnt != nullptr) {
            ListNode *oCnt = cnt;
            bool flag = true;
            for (int i = 0; i < k; i++) {
                if (cnt == nullptr) {
                    flag = false;
                    break;
                }
                cnt = cnt->next;
            }
            if (!flag) { break; }
            reverseK(oCnt, k, last, cnt);
            last = oCnt;
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
                    new ListNode(5)
                )
            )
        )
    );
    auto ans = s.reverseKGroup(x, 2);
    while (ans != nullptr) {
        printf("%d ", ans->val);
        ans = ans->next;
    }
    return 0;
}
