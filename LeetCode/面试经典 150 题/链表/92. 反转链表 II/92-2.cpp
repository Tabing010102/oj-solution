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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        int cidx = 1;
        ListNode *cnt = head;
        ListNode *vhead = new ListNode(0, head);
        ListNode *last = vhead;
        ListNode *pre, *post;
        while (cnt != nullptr) {
            if (cidx == left) { pre = last; }
            if (cidx == right) { post = cnt->next; break; }
            last = cnt;
            cnt = cnt->next;
            cidx++;
        }
        cidx = 1;
        last = vhead;
        cnt = head;
        while (cnt != nullptr) {
            if (cidx == left) {
                reverseK(cnt, right - left + 1, pre, post);
                break;
            }
            last = cnt;
            cnt = cnt->next;
            cidx++;
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
    auto ans = s.reverseBetween(x, 2, 4);
    while (ans != nullptr) {
        printf("%d ", ans->val);
        ans = ans->next;
    }
    return 0;
}
