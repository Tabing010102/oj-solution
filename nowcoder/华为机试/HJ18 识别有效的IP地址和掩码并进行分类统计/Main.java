import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int[] ans = new int[7];
        while (sc.hasNext()) {
            String s = sc.next();
            String s1[] = s.split("~");
            if (s1.length != 2) { ans[5]++; continue; }
            String sIp = s1[0], sMask = s1[1];
            String[] asIp = sIp.split("\\.");
            String[] asMask = sMask.split("\\.");
            if (isIpValid(asIp) && needIgnore(asIp)) { continue; }
            if (!isIpValid(asIp) || !isIpValid(asMask)) { ans[5]++; continue; }
            Ip ip = new Ip(asIp), mask = new Ip(asMask);
            if (!isMaskValid(mask)) { ans[5]++; continue; }
            if (isPrivateIp(ip)) { ans[6]++; }
            int t = getIpCategory(ip);
            if (t >= 0) { ans[t]++; }
            // System.out.println("m " + ans[0] + " " + ans[1] + " " + ans[2] + " " + ans[3] + " " + ans[4] + " " + ans[5] + " " + ans[6]);
    }
        System.out.println(ans[0] + " " + ans[1] + " " + ans[2] + " " + ans[3] + " " + ans[4] + " " + ans[5] + " " + ans[6]);
    }

    static boolean isIpValid(String[] s) {
        try {
            if (s.length != 4) { return false; }
            for (int i = 0; i < 4; i++) {
                int t = Integer.parseInt(s[i]);
                if (t < 0 || t > 255) {
                    return false;
                }
            }
            return true;
        } catch (Exception e) {
            return false;
        }
    }

    static boolean isMaskValid(Ip m) {
        int p = 0;
        while (p < 4 && m.d[p] == 255) { p++; }
        for (int i = p + 1; i < 4; i++) {
            if (m.d[i] != 0) {
                return false;
            }
        }
        if (p == 0 && m.d[0] == 0) {
            return false;
        } else if (p < 4) {
            int t = m.d[p];
            return is2M(256 - t);
        } else {
            return false;
        }
    }

    static boolean is2M(int a) {
        int t = 1;
        while (t < a) { t <<= 1; }
        return t == a;
    }

    static int getIpCategory(Ip ip) {
        if (ip.d[0] >= 1 && ip.d[0] <= 126) { return 0; }
        else if (ip.d[0] >= 128 && ip.d[0] <= 191) { return 1; }
        else if (ip.d[0] >= 192 && ip.d[0] <= 223) { return 2; }
        else if (ip.d[0] >= 224 && ip.d[0] <= 239) { return 3; }
        else { return 4; }
    }

    static boolean isPrivateIp(Ip ip) {
        if ((ip.d[0] == 10)
            || (ip.d[0] == 172 && ip.d[1] >= 16 && ip.d[1] <= 31)
            || (ip.d[0] == 192 && ip.d[1] == 168)) {
            return true;
        }
        return false;
    }

    static boolean needIgnore(String[] a) {
        if (a[0].equals("0") || a[0].equals("127")) { return true; }
        return false;
    }
}

class Ip {
    public int[] d;
    Ip() { d = new int[4]; }
    Ip(String[] a) {
        d = new int[4];
        for (int i = 0; i < 4; i++) {
            d[i] = Integer.parseInt(a[i]);
        }
    }
}