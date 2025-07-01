// User function Template for C++

// Function to return the floor of given number in BST.
int floor(Node* root, int input) {
    // Your code goes here
    int ans=-1;
    while(root!=NULL){
        if(root->data==input) return root->data;
        else if(input<root->data) root=root->left;
        else {
            ans=root->data;
            root=root->right;
        }
    }
    return ans;
}
