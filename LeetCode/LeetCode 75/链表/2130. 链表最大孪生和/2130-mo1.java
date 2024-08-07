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
        while (n1 != null) {
            n1 = n1.next.next;
            if (n1 != null) { n2 = n2.next; }
        }
        ListNode p2n = n2.next;
        // reverse p2n
        n2.next = null;
        ListNode cur = p2n, cur2 = p2n.next;
        while (cur != null && cur2 != null) {
            ListNode cur2Next = cur2.next;
            cur2.next = cur;
            cur = cur2;
            cur2 = cur2Next;
        }
        n2 = cur;
        // solve
        n1 = head;
        int ans = Integer.MIN_VALUE;
        while (n1 != null) {
            ans = Math.max(ans, n1.val + n2.val);
            n1 = n1.next;
            n2 = n2.next;
        }
        return ans;
    }
}