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

