#include "BinaryTree.h"
#include <string>
#include <iostream>
#include <stack>

using namespace std;

void BinaryTree::PreOrder(TreeNode *root)
{

    if (root == nullptr) return;

    cout << "value: " << root->val << endl;

    PreOrder(root->left);

    PreOrder(root->right);
}

void BinaryTree::PreOrderUStack(TreeNode *root)
{
    stack<pair<TreeNode*, string>> nodeStack;

    nodeStack.push(pair<TreeNode*, string>(root, to_string(root->val)));
    
    while (!nodeStack.empty())
    {
       auto [node, path] = nodeStack.top();
       nodeStack.pop();

        cout << node->val << endl;

        if(node->right != nullptr) nodeStack.push(pair<TreeNode*, string>(node->right, to_string(node->right->val)));
        if(node->left != nullptr) nodeStack.push(pair<TreeNode*, string>(node->left, to_string(node->left->val)));

    }
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

    sln->PreOrderUStack(root);
}
