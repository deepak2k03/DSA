/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
class Solution {
  public:
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    vector<int> topView(Node *root) {
        // code here
        vector<int>ans;
        if(root==NULL) return ans;
        map<int,int>m;
        queue<pair<Node*,int>>q;
        q.push({root,0});
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            Node* node=it.first;
            int vertical=it.second;
            if(m.find(vertical)==m.end()) m[vertical]=node->data;
            if(node->left) q.push({node->left,vertical-1});
            if(node->right) q.push({node->right,vertical+1});
        }
        for(auto i:m) ans.push_back(i.second);
        return ans;
        
    }
};
