/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int mx = 0;

    // Helper to calculate height and update max diameter
    int height(TreeNode* root) {
        if (!root) return 0;

        int lh = height(root->left);
        int rh = height(root->right);

        mx = max(mx, lh + rh);  // diameter through this node

        return 1 + max(lh, rh); // return height
    }

    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return mx;
    }
};
