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

int main() {
    // 루트 노드 생성
    TreeNode* root = new TreeNode("a");
    // 왼쪽, 오른쪽 자식 노드 생성
    root->left = new TreeNode("b");
    root->right = new TreeNode("c");
    
    // 노드 값 출력
    cout << root->value << endl;
    cout << root->left->value << endl;
    cout << root->right->value << endl;

    // 메모리 해제
    delete root->left;
    delete root->right;
    delete root;
    
    return 0;
}
