import java.util.*;

class StockSpanner {
    class Node {
        int u, d;

        Node(int u, int d) {
            this.u = u;
            this.d = d;
        }
    }

    ArrayDeque<Node> dq;
    int idx;

    public StockSpanner() {
        dq = new ArrayDeque<>();
        idx = 1;
    }
    
    public int next(int price) {
        // System.out.print("price=%d, dq=".formatted(price));
        // for (Node n : dq) {
        //     System.out.print("{%d, %d} ".formatted(n.u, n.d));
        // }
        // System.out.println();
        if (dq.isEmpty() || price < dq.peek().d) {
            dq.push(new Node(idx++, price));
            return 1;
        } else if (price == dq.peek().d) {
            Node n = dq.poll();
            int t;
            if (dq.isEmpty() || dq.peek().d != price) {
                t = idx - (dq.isEmpty() ? 0 : dq.peek().u);
                dq.push(n);
            } else {
                Node n2 = dq.poll();
                t = idx - (dq.isEmpty() ? 0 : dq.peek().u);
                dq.push(n2);
            }
            dq.push(new Node(idx++, price));
            return t;
        } else {
            while (!dq.isEmpty() && dq.peek().d <= price) { dq.pop(); }
            int t = idx - (dq.isEmpty() ? 0 : dq.peek().u);
            dq.push(new Node(idx++, price));
            return t;
        }
    }
}

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner obj = new StockSpanner();
 * int param_1 = obj.next(price);
 */