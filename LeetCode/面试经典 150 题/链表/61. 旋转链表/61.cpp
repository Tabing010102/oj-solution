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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr) { return head; }
        int n = 0;
        ListNode *cnt = head;
        ListNode *last = nullptr;
        while (cnt != nullptr) {
            last = cnt;
            cnt = cnt->next;
            n++;
        }
        k %= n;
        k = n - k;
        ListNode *ans;
        if (k == 0 || k == n) { return head; }
        else {
            cnt = head;
            ListNode *last2;
            for (int i = 0; i < k - 1; i++) {
                last2 = cnt;
                cnt = cnt->next;
            }
            ans = cnt->next;
            cnt->next = nullptr;
            last->next = head;
        }
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
    auto ans = s.rotateRight(x, 2);
//    ListNode *x = new ListNode(
//        1,
//        new ListNode(
//            2,
//            new ListNode(3)
//        )
//    );
//    auto ans = s.rotateRight(x, 2000000000);
    while (ans != nullptr) {
        printf("%d ", ans->val);
        ans = ans->next;
    }
    return 0;
}
