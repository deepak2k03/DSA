class Solution {
  public:
    // returns the inorder predecessor of the Node x in BST (rooted at 'root')
    int inOrderPredecessor(Node *root, Node *x) {
        Node* pred = NULL;
        while (root != NULL) {
            if (x->data <= root->data) {
                root = root->left;
            } else {
                pred = root;
                root = root->right;
            }
        }
        return pred ? pred->data : -1; // Return -1 if no predecessor exists
    }
};
