#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode < T > *left;
        BinaryTreeNode < T > *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
void changeTree(BinaryTreeNode<int>* root) {
    if (root == NULL)
        return;

    int left = 0;
    int right = 0;

    if (root->left)
        left = root->left->data;

    if (root->right)
        right = root->right->data;

    int sum = left + right;

    // Children sum is greater than current node
    if (sum > root->data) {
        root->data = sum;
    }

    // Children sum is smaller than current node
    else if (sum < root->data) {
        int diff = root->data - sum;

        if (root->left)
            root->left->data += diff;
        else if (root->right)
            root->right->data += diff;
    }

    // Now fix both subtrees
    changeTree(root->left);
    changeTree(root->right);
}