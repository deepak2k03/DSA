/*The Node structure is defined as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

// return the Kth largest element in the given BST rooted at 'root'
class Solution {
  public:
    int count = 0;
    int result = -1;

    void reverseInorder(Node* root, int k) {
        if (!root || count >= k) return;

        reverseInorder(root->right, k);  // Visit right (larger elements)

        count++;
        if (count == k) {
            result = root->data;
            return;
        }

        reverseInorder(root->left, k);  // Visit left (smaller elements)
    }
    int kthLargest(Node *root, int k) {
        // Your code here
        reverseInorder(root, k);
        return result;
        
    }
};
