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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        int cidx = 1;
        ListNode *cnt = head;
        stack<ListNode *> s;
        while (cnt != nullptr) {
            if (cidx >= left && cidx <= right) { s.push(cnt); }
            cnt = cnt->next;
            cidx++;
        }
        ListNode *vhead = new ListNode(0, head);
        cnt = head;
        ListNode *last = vhead;
        cidx = 1;
        while (cnt != nullptr) {
            if (cidx == left) {
                ListNode *rNode = s.top()->next;
                while (!s.empty()) {
                    last->next = s.top();
                    s.pop();
                    last = last->next;
                }
                last->next = rNode;
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
