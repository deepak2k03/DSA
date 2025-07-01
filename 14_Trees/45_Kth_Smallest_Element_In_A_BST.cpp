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
    void f(TreeNode* r,int &c,int k,int &ans){
        if(!r||c>=k) return;
        f(r->left, c, k,ans);
        c++;
        if(c==k){
            ans=r->val;
            return;
        }
        f(r->right, c, k,ans);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int ans=0,c=0;
        f(root,c,k,ans);
        return ans;
    }
};
