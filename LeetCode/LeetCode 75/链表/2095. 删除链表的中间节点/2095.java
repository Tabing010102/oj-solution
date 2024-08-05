
// Definition for singly-linked list.
class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}
 
class Solution {
    public ListNode deleteMiddle(ListNode head) {
        if (head.next == null) { return null; }
        ListNode p1 = head, p2 = head;
        while (p1.next != null) {
            p1 = p1.next;
            if (p1.next != null) {
                p1 = p1.next;
                if (p1.next != null) { p2 = p2.next; }
            }
        }
        p2.next = p2.next.next;
        return head;
    }
}