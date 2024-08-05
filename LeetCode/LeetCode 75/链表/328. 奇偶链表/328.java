
// Definition for singly-linked list.
class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}
 
class Solution {
    public ListNode oddEvenList(ListNode head) {
        if (head == null || head.next == null || head.next.next == null) { return head; }
        ListNode p1 = head, p2 = head.next;
        ListNode op2 = p2;
        while ((p1.next != null && p1.next.next != null) || (p2.next != null && p2.next.next != null)) {
            if (p2.next != null) {
                p1.next = p1.next.next;
                p1 = p1.next;
            }
            if (p2.next != null && p2.next.next != null) {
                p2.next = p2.next.next;
                p2 = p2.next;
            }
        }
        p1.next = op2;
        p2.next = null;
        return head;
    }
}