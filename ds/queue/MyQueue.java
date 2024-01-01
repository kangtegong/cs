import java.util.ArrayList;

class MyQueue {
    private ArrayList<String> items;

    public myQueue() {
        items = new ArrayList<>();
    }

    public void enqueue(String item) {
        items.add(item);
    }

    public String dequeue() {
        if (is_empty()) {
            return null;
        }
        return items.remove(0);
    }

    public boolean is_empty() {
        return items.isEmpty();
    }

    public static void main(String[] args) {
        myQueue q = new myQueue();
        q.enqueue("a");
        q.enqueue("b");
        q.enqueue("c");

        System.out.println(q.dequeue());  // a
        System.out.println(q.dequeue());  // b
        System.out.println(q.dequeue());  // c
    }
}
