#include <iostream>
using namespace std;
class TreeNode
{
public:
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};
int main()
{
    TreeNode *root = new TreeNode(1);
    TreeNode *node2 = new TreeNode(2);
    TreeNode *node3 = new TreeNode(3);
    TreeNode *node4 = new TreeNode(4);
    root->left = node2;
    root->right = node3;
    node2->left = node4;
    cout << "Traversing tree" << endl;
    cout << root->data << endl;
    if (root->left)
    {
        cout << root->left->data << endl;
        if (root->left->left)
        {
            cout << root->left->left->data << endl;
        }
    }
    if (root->right)
    {
        cout << root->right->data << endl;
    }
    return 0;
}