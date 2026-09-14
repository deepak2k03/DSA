//code
/* Structure of a Binary Search Tree node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
}; */

class Solution {
public:

    Node* findLastRight(Node* root) {
        if (root->right == NULL)
            return root;

        return findLastRight(root->right);
    }

    Node* helper(Node* root) {
        if (root->left == NULL)
            return root->right;

        if (root->right == NULL)
            return root->left;

        Node* rightChild = root->right;
        Node* lastRight = findLastRight(root->left);

        lastRight->right = rightChild;

        return root->left;
    }

    Node* delNode(Node* root, int x) {
        if (root == NULL)
            return NULL;

        // Root itself is the node to delete
        if (root->data == x)
            return helper(root);

        Node* dummy = root;

        while (root != NULL) {

            if (root->data > x) {

                if (root->left != NULL && root->left->data == x) {
                    root->left = helper(root->left);
                    break;
                }
                else {
                    root = root->left;
                }

            }
            else {

                if (root->right != NULL && root->right->data == x) {
                    root->right = helper(root->right);
                    break;
                }
                else {
                    root = root->right;
                }
            }
        }

        return dummy;
    }
};