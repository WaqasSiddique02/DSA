#include <iostream>
using namespace std;

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

class BinaryTree {
private:
    TreeNode* root;

    TreeNode* insert(TreeNode* node, int value) {
        if (node == nullptr) {
            return new TreeNode(value);
        }
        if (value < node->data) {
            node->left = insert(node->left, value);
        } else {
            node->right = insert(node->right, value);
        }
        return node;
    }

    void preOrderTraversal(TreeNode* node) {
        if (node != nullptr) {
            cout << node->data << " ";
            preOrderTraversal(node->left);
            preOrderTraversal(node->right);
        }
    }

public:
    BinaryTree() {
        root = nullptr;
    }

    void insert(int value) {
        root = insert(root, value);
    }

    void preOrderTraversal() {
        preOrderTraversal(root);
    }
};

int main() {
    BinaryTree tree;
    tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    tree.insert(2);
    tree.insert(4);

    cout << "Pre-order traversal of the binary tree: ";
    tree.preOrderTraversal();
    cout << endl;

    return 0;
}
