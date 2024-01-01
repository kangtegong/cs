import java.util.ArrayList;
import java.util.List;

public class Graph {
    public static void main(String[] args) {
        List<List<Integer>> graph = new ArrayList<>();
        
        for (int i = 0; i < 5; i++) {
            graph.add(new ArrayList<>());
        }
        
        graph.get(0).add(1);
        graph.get(0).add(4);
        graph.get(1).add(0);
        graph.get(1).add(2);
        graph.get(2).add(1);
        graph.get(2).add(3);
        graph.get(3).add(2);
        graph.get(3).add(4);
        graph.get(4).add(0);
        graph.get(4).add(3);
    }
}
