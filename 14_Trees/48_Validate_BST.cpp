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
    void f(TreeNode* r,vector<int>&v){
        if(!r) return;
        f(r->left,v);
        v.push_back(r->val);
        f(r->right,v);
    }
    bool isValidBST(TreeNode* root) {
        vector<int>v;
        f(root,v);
        for(int i=0;i<v.size()-1;i++) if(v[i]>=v[i+1]) return false;
        return true;
    }
};

//second approach - giving nodes a range

class Solution {
  public:
    bool valid(Node*root, int low, int high){
        if(!root) return true;
        if(root->data<=low || root->data>=high) return false;
        return valid(root->left, low, root->data) && valid(root->right, root->data, high);
    }
    bool isBST(Node* root) {
        // code here
        return valid(root, INT_MIN, INT_MAX);
    }
};