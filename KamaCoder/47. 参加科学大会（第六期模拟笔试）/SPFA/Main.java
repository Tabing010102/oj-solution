import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

class Solution {
    final int MAXN = 500 + 10;
    final int MAXM = 5000 + 10;
    final int INF = Integer.MAX_VALUE;

    class Edge {
        public int from, to, dist;

        public Edge(int f, int t, int d) {
            this.from = f;
            this.to = t;
            this.dist = d;
        }
    }
    class HeapNode implements Comparable<HeapNode> {
        int u, dist;

        public HeapNode(int u, int d) {
            this.u = u;
            this.dist = d;
        }

        @Override
        public int compareTo(HeapNode o) {
            if (this.dist == o.dist) {
                return 0;
            } else if (this.dist > o.dist) {
                return -1;
            } else {
                return 1;
            }
        }
    }

    int n;
    public int[] d = new int[MAXN];
    int[] cnt = new int[MAXN];
    boolean[] inq = new boolean[MAXN];
    ArrayList<ArrayList<Integer>> G = new ArrayList<ArrayList<Integer>>();
    ArrayList<Edge> edges = new ArrayList<>();
    ArrayDeque<Integer> q = new ArrayDeque<>();

    public void init(int n) {
        this.n = n;
        G.ensureCapacity(n + 1);
        for (int i = 0; i <= n; i++) {
            G.add(new ArrayList<Integer>());
        }
        edges.clear();
        q.clear();
    }

    public void addEdge(int u1, int u2, int dist) {
        edges.add(new Edge(u1, u2, dist));
        G.get(u1).add(edges.size() - 1);
    }

    public boolean spfa(int s) {
        Arrays.fill(d, INF);
        d[s] = 0;
        Arrays.fill(cnt, 0);
        Arrays.fill(inq, false);
        q.add(s);
        inq[s] = true;
        while (!q.isEmpty()) {
            int u = q.poll();
            inq[u] = false;
            for (Integer eIdx : G.get(u)) {
                Edge e = edges.get(eIdx);
                if (d[u] < INF && d[e.to] > d[u] + e.dist) {
                    d[e.to] = d[u] + e.dist;
                    if (!inq[e.to]) {
                        q.add(e.to);
                        inq[e.to] = true;
                        if (++cnt[e.to] > n) { return false; }
                    }
                }
            }
        }
        return true;
    }
}

public class Main {
    public static void main(String[] args) {
        Solution s = new Solution();
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        s.init(n);
        int m = sc.nextInt();
        for (int i = 0; i < m; i++) {
            int f = sc.nextInt();
            int t = sc.nextInt();
            int d = sc.nextInt();
            s.addEdge(f, t, d);
        }
        if (!s.spfa(1) || s.d[n] == Integer.MAX_VALUE) {
            System.out.println("-1");
        } else {
            System.out.println(s.d[n]);
        }
        sc.close();
    }
}
