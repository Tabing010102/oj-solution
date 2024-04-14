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
    ListNode* partition(ListNode* head, int x) {
        ListNode *lvhead = new ListNode(0);
        ListNode *rvhead = new ListNode(0);
        ListNode *lp = lvhead, *rp = rvhead;
        ListNode *cnt = head;
        while (cnt != nullptr) {
            if (cnt->val < x) {
                lp->next = cnt;
                lp = cnt;
            } else {
                rp->next = cnt;
                rp = cnt;
            }
            cnt = cnt->next;
        }
        lp->next = rvhead->next;
        rp->next = nullptr;
        ListNode *ans = lvhead->next;
        delete lvhead;
        delete rvhead;
        return ans;
    }
};

int main() {
    Solution s;
    ListNode *x = new ListNode(
        1,
        new ListNode(
            4,
            new ListNode(
                3,
                new ListNode(
                    2,
                    new ListNode(
                        5,
                        new ListNode(2)
                    )
                )
            )
        )
    );
    auto ans = s.partition(x, 3);
    while (ans != nullptr) {
        printf("%d ", ans->val);
        ans = ans->next;
    }
    return 0;
}
