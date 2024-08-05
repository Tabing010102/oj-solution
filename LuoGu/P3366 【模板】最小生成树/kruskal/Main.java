import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int M = sc.nextInt();
        ArrayList<Edge> edges = new ArrayList<>(M);
        for (int i = 0; i < M; i++) {
            int f, t, d;
            f = sc.nextInt();
            t = sc.nextInt();
            d = sc.nextInt();
            edges.add(new Edge(f, t, d));
        }
        sc.close();
        int[] fa = new int[N + 1];
        for (int i = 1; i <= N; i++) { fa[i] = i; }
        Collections.sort(edges);
        int ans = 0, eCount = 0;
        for (int i = 0; i < M && eCount < N - 1; i++) {
            Edge e = edges.get(i);
            int fa1 = find(fa, e.from);
            int fa2 = find(fa, e.to);
            if (fa1 == fa2) { continue; }
            fa[fa1] = fa2;
            ans += e.dist;
            eCount++;
        }
        if (eCount == N - 1) {
            System.out.println(ans);
        } else {
            System.out.println("orz");
        }
    }
    static int find(int[] fa, int x) { return x == fa[x] ? x : (fa[x] = find(fa, fa[x])); }
}

class Edge implements Comparable<Edge> {
    int from, to, dist;

    public Edge(int f, int t, int d) {
        from = f;
        to = t;
        dist = d;
    }

    @Override
    public int compareTo(Edge e) {
        if (dist == e.dist) {
            return 0;
        } else if (dist < e.dist) {
            return -1;
        } else {
            return 1;
        }
    }
}
