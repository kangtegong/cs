import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class CV {
    private static final Lock lock = new ReentrantLock();
    private static final Condition cond = lock.newCondition();
    private static boolean ready = false;

    public static void main(String[] args) throws InterruptedException {
        Thread t1 = new Thread(new ThreadJob1());
        Thread t2 = new Thread(new ThreadJob2());
        t1.start();
        t2.start();
        t1.join();
        t2.join();
    }

    static class ThreadJob1 implements Runnable {
        @Override
        public void run() {
            System.out.println("P1: 먼저 시작");
            lock.lock();
            try {
                System.out.println("P1: 2초 대기");
                while (!ready) {
                    cond.await(); // 조건 변수 wait
                }
            } catch (InterruptedException e) {
                e.printStackTrace();
            } finally {
                lock.unlock();
            }
            System.out.println("P1: 다시 시작");
            System.out.println("P1: 종료");
        }
    }

    static class ThreadJob2 implements Runnable {
        @Override
        public void run() {
            System.out.println("P2: 2초 실행 시작");
            try {
                Thread.sleep(2000); // 2초 대기
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
            System.out.println("P2: 실행 완료");
            lock.lock();
            try {
                ready = true;
                cond.signal(); // 조건 변수 signal
            } finally {
                lock.unlock();
            }
        }
    }
}
