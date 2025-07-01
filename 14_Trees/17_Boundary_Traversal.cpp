/*
// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    bool isLeaf(Node* node){
        return node->left==NULL && node->right==NULL;
    }
    
    void addLeftBoundary(Node* node, vector<int> &v){
        Node* cur=node->left;
        while(cur){
            if(!isLeaf(cur)) v.push_back(cur->data);
            if(cur->left!=NULL) cur=cur->left;
            else cur=cur->right;
        }
    }
    
    void addRightBoundary(Node* node, vector<int> &v){
        vector<int>temp;
        Node* cur=node->right;
        while(cur){
            if(!isLeaf(cur)) temp.push_back(cur->data);
            if(cur->right!=NULL) cur=cur->right;
            else cur=cur->left;
        }
        for(int i=temp.size()-1;i>=0;i--) v.push_back(temp[i]);
    }
    
    void addLeaves(Node* node, vector<int> &v){
        if(isLeaf(node)){
            v.push_back(node->data);
            return;
        }
        if(node->left) addLeaves(node->left,v);
        if(node->right) addLeaves(node->right,v);
    }
    
    vector<int> boundaryTraversal(Node *root) {
        // code here
        vector<int>v;
        if(root==NULL) return v;
        if(!isLeaf(root)) v.push_back(root->data);
        addLeftBoundary(root, v);
        addLeaves(root, v);
        addRightBoundary(root, v);
        return v;
    }
};
