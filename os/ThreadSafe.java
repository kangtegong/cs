import java.util.*;
public class ThreadSafe {

    public static void main(String[] args) throws InterruptedException {
        // ArrayList와 Vector 생성
        List<Integer> arrayList = new ArrayList<>();
        List<Integer> vector = new Vector<>();

        // ArrayList와 Vector에 요소를 추가하는 스레드 생성
        Thread arrayListThread1 = new Thread(() -> addElements(arrayList, 0, 5000));
        Thread arrayListThread2 = new Thread(() -> addElements(arrayList, 5000, 10000));

        Thread vectorThread1 = new Thread(() -> addElements(vector, 0, 5000));
        Thread vectorThread2 = new Thread(() -> addElements(vector, 5000, 10000));

        arrayListThread1.start();
        arrayListThread2.start();

        vectorThread1.start();
        vectorThread2.start();

        arrayListThread1.join();
        arrayListThread2.join();

        vectorThread1.join();
        vectorThread2.join();

        System.out.println("ArrayList size: " + arrayList.size());
        System.out.println("Vector size: " + vector.size());
    }

    private static void addElements(List<Integer> list, int start, int end) {
        for (int i = start; i < end; i++) {
            list.add(i);
        }
    }
}
