class TreeNode:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None

# 루트 노드 생성
root = TreeNode("a")

# 왼쪽, 오른쪽 자식 노드 생성
root.left = TreeNode("b")
root.right = TreeNode("c")

def inorder_traversal(node):
    if node:
        # 왼쪽 서브트리를 먼저 방문
        inorder_traversal(node.left)
        # 현재 노드 방문
        print(node.value)
        # 오른쪽 서브트리 방문
        inorder_traversal(node.right)

inorder_traversal(root)

