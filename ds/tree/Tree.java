class TreeNode {
    String value;
    TreeNode left;
    TreeNode right;
    
    TreeNode(String val) {
        value = val;
        left = null;
        right = null;
    }
}

public class Tree {
    public static void main(String[] args) {
        // 루트 노드 생성
        TreeNode root = new TreeNode("a");
        // 왼쪽, 오른쪽 자식 노드 생성
        root.left = new TreeNode("b");
        root.right = new TreeNode("c");
        
        // 노드 값 출력
        System.out.println(root.value);
        System.out.println(root.left.value);
        System.out.println(root.right.value);
    }
}
