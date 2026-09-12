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
unordered_map<TreeNode*, TreeNode*>parent;
    void inorder(TreeNode* root){
        if(!root) return;
        if(root->left) parent[root->left]=root;
        inorder(root->left);
        if(root->right) parent[root->right]=root;
        inorder(root->right);
    }

    void bfs(TreeNode* target, int &ans){
        queue<TreeNode*>q;
        q.push(target);
        unordered_set<int>vis;
        vis.insert(target->val);
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                TreeNode* cur=q.front();
                q.pop();

                //left
                if(cur->left!=NULL && !vis.count(cur->left->val)){
                    q.push(cur->left);
                    vis.insert(cur->left->val);
                }

                //right
                if(cur->right!=NULL && !vis.count(cur->right->val)){
                    q.push(cur->right);
                    vis.insert(cur->right->val);
                }

                //parent
                if(parent.count(cur) && !vis.count(parent[cur]->val)){
                    q.push(parent[cur]);
                    vis.insert(parent[cur]->val);
                }
            }
            if(!q.empty()) ans++;
        }
    }

    TreeNode* findTarget(TreeNode* root, int target) {
        if (!root) return NULL;
        if (root->val == target) return root;
        TreeNode* left = findTarget(root->left, target);
        if (left) return left;
        return findTarget(root->right, target);
    }

class Solution {
  public:
    int amountOfTime(TreeNode* root, int start) {
        // code here
        int ans=0;
        inorder(root);
        TreeNode* targetNode = findTarget(root, start);
        bfs(targetNode, ans);
        return ans;
    }
};