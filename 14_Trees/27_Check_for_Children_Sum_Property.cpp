/*Complete the function below

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){80
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    // Function to check whether all nodes of a tree have the value
    // equal to the sum of their child nodes.
    int isSumProperty(Node *root) {
        // Add your code here
        if (root == NULL || (root->left == NULL && root->right == NULL)) return 1;
        int child=0;
        if(root->left) child+=root->left->data;
        if(root->right) child+=root->right->data;
        if ((root->data == child) &&
            isSumProperty(root->left) &&
            isSumProperty(root->right)) {
            return 1;
        } 
        else return 0;
    }
};
