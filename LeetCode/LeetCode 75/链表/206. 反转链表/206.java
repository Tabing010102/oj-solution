// Definition for singly-linked list.
class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}

class Solution {
    public ListNode reverseList(ListNode head) {
        if (head == null) { return head; }
        ListNode cur = head, cur2 = head.next;
        head.next = null;
        while (cur != null && cur2 != null) {
            // System.out.println("%d, %d".formatted(cur.val, cur2.val));
            ListNode cur2Next = cur2.next;
            cur2.next = cur;
            cur = cur2;
            cur2 = cur2Next;
        }
        return cur;
    }
}