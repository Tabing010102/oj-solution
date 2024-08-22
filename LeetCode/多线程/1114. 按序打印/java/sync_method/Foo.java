class Foo {
    private boolean r1Done, r2Done;
    private Object lock;

    public Foo() {
        r1Done = false;
        r2Done = false;
        lock = new Object();
    }

    public void first(Runnable printFirst) throws InterruptedException {
        synchronized(lock) {
            // printFirst.run() outputs "first". Do not change or remove this line.
            printFirst.run();
            r1Done = true;
            lock.notifyAll();
        }
    }

    public void second(Runnable printSecond) throws InterruptedException {
        synchronized(lock) {
            while (!r1Done) {
                lock.wait();
            }
            // printSecond.run() outputs "second". Do not change or remove this line.
            printSecond.run();
            r2Done = true;
            lock.notifyAll();
        }
    }

    public void third(Runnable printThird) throws InterruptedException {
        synchronized(lock) {
            while (!r2Done) {
                lock.wait();
            }
            // printThird.run() outputs "third". Do not change or remove this line.
            printThird.run();
        }
    }
}