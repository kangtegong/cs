class TreeNode {
    constructor(value) {
        this.value = value;
        this.left = null;
        this.right = null;
    }
}

// 루트 노드 생성
const root = new TreeNode("a");
// 왼쪽, 오른쪽 자식 노드 생성
root.left = new TreeNode("b");
root.right = new TreeNode("c");

// 확인을 위해 노드 값 출력
console.log(root.value);
console.log(root.left.value);
console.log(root.right.value);
