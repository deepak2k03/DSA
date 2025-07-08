/* BST Node
class Node
{
   public:
    int data;
    Node *left;
    Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
}; */

class Solution {
  public:
    Node* inOrderSuccessor(Node *root, int x) {
    Node* succ = NULL;
    while (root != NULL) {
        if (x>= root->data) {
            root = root->right;
        } else {
            succ = root;
            root = root->left;
        }
    }
    return succ;
    }

    // returns the inorder predecessor of the Node x in BST (rooted at 'root')
    Node* inOrderPredecessor(Node *root, int x) {
        Node* pred = NULL;
        while (root != NULL) {
            if (x <= root->data) {
                root = root->left;
            } else {
                pred = root;
                root = root->right;
            }
        }
        return pred; // Return -1 if no predecessor exists
    }


    vector<Node*> findPreSuc(Node* root, int key) {
        // code here
        Node* s=inOrderSuccessor(root,key);
        Node* p=inOrderPredecessor(root,key);
        return {p,s};
    }
};