import java.util.*;

public class Main {
    static Random random = new Random();
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
        // mid
        // int m = l + (r - l) / 2;
        int m = random.nextInt(oR - oL + 1) + oL;
        int t;
        if ((d[m] > d[l] && d[m] < d[r]) || (d[m] > d[r] && d[m] < d[l])) {
            t = d[m];
            d[m] = d[l];
            d[l] = t;
        } else if ((d[r] > d[l] && d[r] < d[m]) || (d[r] > d[m] && d[r] < d[l])) {
            t = d[r];
            d[r] = d[l];
            d[l] = t;
        }
        int p = d[l];
        while (l < r) {
            while (l < r && d[r] > p) { r--; }
            if (l < r) { d[l++] = d[r]; }
            while (l < r && d[l] < p) { l++; }
            if (l < r) { d[r--] = d[l]; }
        }
        d[l] = p;
        qsort(d, oL, l - 1);
        qsort(d, l + 1, oR);
    }
}
