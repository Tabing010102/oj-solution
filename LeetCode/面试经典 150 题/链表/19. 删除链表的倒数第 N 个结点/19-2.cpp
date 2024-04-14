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

int N;

class Solution {
public:
    int dfs(ListNode *cnt, ListNode *last) {
        if (cnt == nullptr) { return 1; }
        int idx = dfs(cnt->next, cnt);
        if (idx == N) {
            ListNode *oNext = cnt->next;
            last->next = oNext;
            delete cnt;
        }
        return idx + 1;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        N = n;
        ListNode *vhead = new ListNode(0, head);
        dfs(head, vhead);
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
