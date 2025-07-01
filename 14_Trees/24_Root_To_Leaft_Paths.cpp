/*

Definition for Binary Tree Node
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    void f(Node* root, vector<vector<int>> &v, vector<int>&temp){
        if(root==NULL) return ;
        temp.push_back(root->data);
        if(root->right==NULL && root->left==NULL) v.push_back(temp);
        f(root->left,v,temp);
        f(root->right,v,temp);
        temp.pop_back();
    }
    vector<vector<int>> Paths(Node* root) {
        // code here
        vector<vector<int>>v;
        vector<int>temp;
        if(root==NULL) return v;
        f(root,v,temp);
        return v;
    }
};
