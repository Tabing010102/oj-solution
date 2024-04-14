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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = 0;
        ListNode *cnt = head;
        while (cnt != nullptr) {
            len++;
            cnt = cnt->next;
        }
        ListNode *vhead = new ListNode(0, head);
        int cidx = 0;
        cnt = head;
        ListNode *last = vhead;
        while (cnt != nullptr) {
            if (cidx == len - n) {
                ListNode *oNext = cnt->next;
                last->next = oNext;
                delete cnt;
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
    auto ans = s.removeNthFromEnd(x, 2);
    while (ans != nullptr) {
        printf("%d ", ans->val);
        ans = ans->next;
    }
    return 0;
}
