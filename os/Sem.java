import java.util.concurrent.Semaphore;

public class Sem {
    static int sharedData = 0; // 공유 데이터
    // 세마포 생성, 공유 자원 1개
    static Semaphore semaphore = new Semaphore(1);

    public static void main(String[] args) {
        Thread thread1 = new Thread(new Increment());
        Thread thread2 = new Thread(new Decrement());

        thread1.start(); // 첫 번째 스레드 시작
        thread2.start(); // 두 번째 스레드 시작
        try {
            thread1.join(); // 첫 번째 스레드 종료 대기
            thread2.join(); // 두 번째 스레드 종료 대기
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        System.out.println("Final value of sharedData: " + sharedData);
    }

    static class Increment implements Runnable {
        public void run() {
            for (int i = 0; i < 100000; i++) {
                try {
                    semaphore.acquire(); // 세마포 획득
                    sharedData++; // 공유 데이터 증가
                } catch (InterruptedException e) {
                    e.printStackTrace();
                } finally {
                    semaphore.release(); // 세마포 해제
                }
            }
        }
    }

    static class Decrement implements Runnable {
        public void run() {
            for (int i = 0; i < 100000; i++) {
                try {
                    semaphore.acquire(); // 세마포 획득
                    sharedData--; // 공유 데이터 감소
                } catch (InterruptedException e) {
                    e.printStackTrace();
                } finally {
                    semaphore.release(); // 세마포 해제
                }
            }
        }
    }
}
