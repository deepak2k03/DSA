/* A binary tree node

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
    void f(Node* root, int level, vector<int> &v){
        if(root==NULL) return;
        if(v.size()==level) v.push_back(root->data);
        f(root->left,level+1,v);
        f(root->right,level+1,v);
    }
    vector<int> leftView(Node *root) {
        // code here
        vector<int>v;
        f(root,0,v);
        return v;
    }
};
