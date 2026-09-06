/* Structure of Binary Tree Node
class Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution {
  public:
    vector<int> zigZagTraversal(Node* root) {
        // code here
        vector<int>ans;
        if(!root) return ans;
        queue<Node*>q;
        bool ltr=1;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int>row(size);
            for(int i=0;i<size;i++){
                Node* node = q.front();
                q.pop();
                if(ltr==1) row[i]=node->data;
                else row[size-i-1]=node->data;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            ltr=!ltr;
            for(auto i:row) ans.push_back(i);
        }
        return ans;
    }
};