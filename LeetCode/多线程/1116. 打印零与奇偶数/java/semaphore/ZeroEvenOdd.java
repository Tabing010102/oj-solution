import java.util.concurrent.Semaphore;
import java.util.function.IntConsumer;

class ZeroEvenOdd {
    private int n;
    private Semaphore sz, se, so;
    private volatile int curN;
    
    public ZeroEvenOdd(int n) {
        this.n = n;
        sz = new Semaphore(1);
        se = new Semaphore(0);
        so = new Semaphore(0);
        curN = 1;
    }

    // printNumber.accept(x) outputs "x", where x is an integer.
    public void zero(IntConsumer printNumber) throws InterruptedException {
        while (curN <= n) {
            // System.out.println("acquiring sz, curN = " + curN + ", n = " + n);
            sz.acquire();
            if (curN > n) { break; }
            // System.out.println("acquired sz, curN = " + curN + ", n = " + n);
            printNumber.accept(0);
            boolean last = curN >= n;
            if (curN % 2 == 0) { se.release(); }
            else { so.release(); }
            if (last) { break; }
        }
        // System.out.println("exiting zero");
    }

    public void even(IntConsumer printNumber) throws InterruptedException {
        while (curN <= ((n % 2 == 0) ? n : n - 1)) {
            // System.out.println("acquiring se, curN = " + curN + ", n = " + n);
            se.acquire();
            // System.out.println("acquired se, curN = " + curN + ", n = " + n);
            printNumber.accept(curN);
            curN++;
            sz.release();
            if (curN - 1 >= ((n % 2 == 0) ? n : n - 1)) { break; }
        }
        // System.out.println("exiting even");
    }

    public void odd(IntConsumer printNumber) throws InterruptedException {
        while (curN <= ((n % 2 == 1) ? n : n - 1)) {
            // System.out.println("acquiring so, curN = " + curN + ", n = " + n);
            so.acquire();
            // System.out.println("acquired so, curN = " + curN + ", n = " + n);
            printNumber.accept(curN);
            curN++;
            sz.release();
            if (curN - 1 >= ((n % 2 == 1) ? n : n - 1)) { break; }
        }
        // System.out.println("exiting odd");
    }
}