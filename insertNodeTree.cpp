#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

Node *insert(Node *root, int key)
{
    if (root == NULL)
    {
        return new Node(key);
    }
    if (key < root->data)
    {
        root->left = insert(root->left, key);
    }
    else
    {
        root->right = insert(root->right, key);
    }
    return root;
}

void inorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
int main()
{
    Node *root = NULL;
    root = insert(root, 15);
    insert(root, 10);
    insert(root, 20);
    insert(root, 25);
    inorder(root);
    return 0;
}