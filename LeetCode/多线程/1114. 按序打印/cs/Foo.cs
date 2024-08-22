using System.Threading;

public class Foo {
    private ManualResetEventSlim _mres2 = new ManualResetEventSlim();
    private ManualResetEventSlim _mres3 = new ManualResetEventSlim();

    public Foo()
    {    
    }

    public void First(Action printFirst) {
        
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();

        _mres2.Set();
    }

    public void Second(Action printSecond) {
        _mres2.Wait();
        _mres2.Reset();

        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();

        _mres3.Set();
    }

    public void Third(Action printThird) {
        _mres3.Wait();
        _mres3.Reset();
        
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
}
