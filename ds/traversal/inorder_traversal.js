class TreeNode {
    constructor(value) {
        this.value = value;
        this.left = null;
        this.right = null;
    }
}

function inorderTraversal(node) {
    if (node !== null) {
        // 왼쪽 서브트리를 먼저 방문
        inorderTraversal(node.left);
        // 현재 노드 방문
        console.log(node.value);
        // 오른쪽 서브트리 방문
        inorderTraversal(node.right);
    }
}

// 루트 노드 생성
const root = new TreeNode("a");
// 왼쪽, 오른쪽 자식 노드 생성
root.left = new TreeNode("b");
root.right = new TreeNode("c");

inorderTraversal(root);
