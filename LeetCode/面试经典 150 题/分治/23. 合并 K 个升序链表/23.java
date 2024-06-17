/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public final int INF = (int)1e4 + 10;
    private int getMinLNVal(ListNode[] lnList) {
        int currVal = INF;
        for (ListNode node : lnList) {
            if (node != null && currVal > node.val) {
                currVal = node.val;
            }
        }
        return currVal;
    }
    public ListNode mergeKLists(ListNode[] lists) {
        ListNode vhead = new ListNode();
        ListNode curr = vhead;
        int currVal = getMinLNVal(lists);
        while (currVal < INF) {
            for (int i = 0; i < lists.length; i++) {
                ListNode node = lists[i];
                if (node != null && node.val == currVal) {
                    curr.next = new ListNode(currVal);
                    lists[i] = node.next;
                    curr = curr.next;
                }
            }
            currVal = getMinLNVal(lists);
        }
        return vhead.next;
    }
}