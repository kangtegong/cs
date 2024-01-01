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

public class InorderTraversal {
    public static void inorderTraversal(TreeNode node) {
        if (node != null) {
            // 왼쪽 서브트리를 먼저 방문
            inorderTraversal(node.left);
            // 현재 노드 방문
            System.out.print(node.value + " ");
            // 오른쪽 서브트리 방문
            inorderTraversal(node.right);
        }
    }

    public static void main(String[] args) {
        // 루트 노드 생성
        TreeNode root = new TreeNode("a");
        // 왼쪽, 오른쪽 자식 노드 생성
        root.left = new TreeNode("b");
        root.right = new TreeNode("c");
        
        inorderTraversal(root);
    }
}
