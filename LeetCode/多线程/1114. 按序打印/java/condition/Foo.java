import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.ReentrantLock;

public class Foo {

    private ReentrantLock rlock = new ReentrantLock();
    private Condition c2 = rlock.newCondition();
    private Condition c3 = rlock.newCondition();
    private boolean r1Done = false;
    private boolean r2Done = false;

    public Foo() {
    }

    public void first(Runnable printFirst) throws InterruptedException {
        rlock.lock();
        try {

            // printFirst.run() outputs "first". Do not change or remove this line.
            printFirst.run();

            r1Done = true;
            c2.signal();
        } finally {
            rlock.unlock();
            System.out.println("r1Done");
        }
    }

    public void second(Runnable printSecond) throws InterruptedException {
        rlock.lock();
        try {
            while (!r1Done) {
                c2.await();
            }

            // printSecond.run() outputs "second". Do not change or remove this line.
            printSecond.run();

            r2Done = true;
            c3.signal();
        } finally {
            rlock.unlock();
        }
    }

    public void third(Runnable printThird) throws InterruptedException {
        rlock.lock();
        try {
            while (!r2Done) {
                c3.await();
            }
            
            // printThird.run() outputs "third". Do not change or remove this line.
            printThird.run();
        } finally {
            rlock.unlock();
        }
    }

    public static void main(String[] args) throws Exception {
        Foo foo = new Foo();
        // Thread t1 = new Thread(() -> {foo.first(() -> { sfirst(); });});
        Thread t1 = new Thread(() -> {
            try {
                foo.first(() -> { sfirst(); });
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        });
        Thread t2 = new Thread(() -> {
            try {
                foo.second(() -> { ssecond(); });
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        });
        Thread t3 = new Thread(() -> {
            try {
                foo.third(() -> { sthird(); });
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        });
        t1.start();
        Thread.sleep(20000);
        t2.start();
        Thread.sleep(20000);
        t3.start();

        Thread.sleep(10000);
    }
    static void sfirst() { System.out.println("first"); }
    static void ssecond() { System.out.println("second"); }
    static void sthird() { System.out.println("third"); }
}
