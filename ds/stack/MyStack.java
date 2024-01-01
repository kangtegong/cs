import java.util.ArrayList;

class MyStack {
    private ArrayList<String> items;

    public myStack() {
        items = new ArrayList<>();
    }

    public void push(String item) {
        items.add(item);
    }

    public String pop() {
        if (is_empty()) {
            return null;
        }
        return items.remove(items.size() - 1);
    }

    public boolean is_empty() {
        return items.size() == 0;
    }

    public static void main(String[] args) {
        myStack s = new myStack();
        s.push("a");
        s.push("b");
        s.push("c");

        System.out.println(s.pop());  // c
        System.out.println(s.pop());  // b
        System.out.println(s.pop());  // a
    }
}
