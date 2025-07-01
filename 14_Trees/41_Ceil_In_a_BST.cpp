/* struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};  */

int findCeil(Node* root, int input) {
    // Your code here
    int ans=-1;
    while(root!=NULL){
        if(root->data==input) return root->data;
        else if(input>root->data) root=root->right;
        else {
            ans=root->data;
            root=root->left;
        }
    }
    return ans;
}
