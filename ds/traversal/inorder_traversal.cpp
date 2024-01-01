#include <iostream>
using namespace std;

class TreeNode {
public:
    string value;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(string val) {
        value = val;
        left = nullptr;
        right = nullptr;
    }
};

void inorderTraversal(TreeNode* node) {
    if (node != nullptr) {
        // 왼쪽 서브트리를 먼저 방문
        inorderTraversal(node->left);
        // 현재 노드 방문
        cout << node->value << " ";
        // 오른쪽 서브트리 방문
        inorderTraversal(node->right);
    }
}

int main() {
    // 루트 노드 생성
    TreeNode* root = new TreeNode("a");
    // 왼쪽, 오른쪽 자식 노드 생성
    root->left = new TreeNode("b");
    root->right = new TreeNode("c");
    
    inorderTraversal(root);
    return 0;
}
