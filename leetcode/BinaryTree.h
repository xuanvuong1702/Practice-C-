
#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <vector>
#include <string>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(NULL), right(NULL) {}
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class BinaryTree {
public:
    void PreOrder(TreeNode* root);
    void InOrder(TreeNode* root);
    void PostOrder(TreeNode* root);
    void PreOrderUStack(TreeNode* root);
};

void RunBinaryTree();

#endif