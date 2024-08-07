import java.util.*;

// Definition for singly-linked list.
class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}

class Solution {
    public int pairSum(ListNode head) {
        ListNode n1 = head, n2 = head;
        ArrayDeque<ListNode> dq = new ArrayDeque<>();
        while (n1 != null) {
            n1 = n1.next.next;
            dq.push(n2);
            n2 = n2.next;
        }
        int ans = Integer.MIN_VALUE;
        while (!dq.isEmpty()) {
            ans = Math.max(ans, dq.pop().val + n2.val);
            n2 = n2.next;
        }
        return ans;
    }
}