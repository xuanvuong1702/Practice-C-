#include "BinaryTree.h"
#include <string>
#include <iostream>

using namespace std;

void BinaryTree::PreOrder(TreeNode *root)
{

    if (root == nullptr) return;

    cout << "value: " << root->val << endl;

    PreOrder(root->left);

    PreOrder(root->right);
}

void BinaryTree::InOrder(TreeNode *root)
{
    if (root == NULL)
        return;
 
    // First recur on left subtree
    InOrder(root->left);
 
    // Now deal with the node
    cout << "value: " << root->val << endl;
 
    // Then recur on right subtree
    InOrder(root->right);
}

void BinaryTree::PostOrder(TreeNode *root)
{
    if(root == NULL) return;

    PostOrder(root->left);

    PostOrder(root->right);

    cout << "value: " << root->val << endl;
}

void RunBinaryTree()
{
    BinaryTree *sln = new BinaryTree();

    TreeNode *node5 = new TreeNode(5);
    TreeNode *node2 = new TreeNode(2, nullptr, node5);
    TreeNode *node3 = new TreeNode(3);

    TreeNode *root = new TreeNode(1, node2, node3);

    sln->PostOrder(root);
}
