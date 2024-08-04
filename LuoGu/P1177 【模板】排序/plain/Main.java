import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] d = new int[n];
        for (int i = 0; i < n; i++) {
            d[i] = sc.nextInt();
        }
        sc.close();

        qsort(d, 0, n - 1);

        for (int i = 0; i < n; i++) {
            System.out.print(String.valueOf(d[i]) + " ");
        }
    }
    static void qsort(int[] d, int l, int r) {
        if (r - l + 1 <= 1) { return; }
        int oL = l, oR = r;
        int p = d[l];
        while (l < r) {
            while (l < r && d[r] >= p) { r--; }
            d[l] = d[r];
            while (l < r && d[l] <= p) { l++; }
            d[r] = d[l];
        }
        d[l] = p;
        qsort(d, oL, l - 1);
        qsort(d, l + 1, oR);
    }
}
