/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void mark_parent(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent_track, TreeNode* Tareget){
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* cur=q.front();
            q.pop();
            if(cur->left){
                parent_track[cur->left]=cur;
                q.push(cur->left);
            }
            if(cur->right){
                parent_track[cur->right]=cur;
                q.push(cur->right);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*>parent_track;
        mark_parent(root,parent_track,target);
        unordered_map<TreeNode*, bool>vis;
        queue<TreeNode*>q;
        q.push(target);
        vis[target]=1;
        int cur_lvl=0;
        while(!q.empty()){
            int size=q.size();
            if(cur_lvl++==k) break;
            for(int i=0;i<size;i++){
                TreeNode* cur = q.front();
                q.pop();
                if(cur->left && !vis[cur->left]){
                    q.push(cur->left);
                    vis[cur->left]=1;
                }
                if(cur->right && !vis[cur->right]){
                    q.push(cur->right);
                    vis[cur->right]=1;
                }
                if(parent_track[cur] && !vis[parent_track[cur]]){
                    q.push(parent_track[cur]);
                    vis[parent_track[cur]]=1;
                }
            }
        }
        vector<int>v;
        while(!q.empty()){
            v.push_back(q.front()->val);
            q.pop();
        }
        return v;

    }
};