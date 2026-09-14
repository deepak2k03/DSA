/* Structure of a Binary Search Tree node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
}; */

class Solution {
  public:
  Node* inorderPredecessor(Node* root, int key) {
      Node* pred = NULL;

      while (root != NULL) {
          if (root->data < key) {
              pred = root;
              root = root->right;
          } else {
              root = root->left;
          }
      }

      return pred;
  }
  Node* inOrderSuccessor(Node *root, int key) {
          // Your code here
          Node* succ=NULL;
          while(root!=NULL){
              if(key>=root->data) root=root->right;
              else{
                  succ=root;
                  root=root->left;
              }
          }
          return succ;
      }
    vector<Node*> findPreSuc(Node* root, int key) {
        // code here
        vector<Node*>ans;
        Node* suc=inOrderSuccessor(root,key);
        Node* pred=inorderPredecessor(root,key);
        ans.push_back(pred);
        ans.push_back(suc);
        return ans;
    }
};