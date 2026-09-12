class Solution {
  public:
    
    int leftHeight(Node* node){
        int height=0;
        while(node){
            height++;
            node=node->left;
        }
        return height;
    }
    
    int rightHeight(Node* node){
        int height=0;
        while(node){
            height++;
            node=node->right;
        }
        return height;
    }
    int countNodes(Node* root) {
        // code here
        if(!root) return 0;
        
        int lh=leftHeight(root);
        int rh=rightHeight(root);

        if(lh==rh) return (1<<rh) -1;
        
        return 1 + countNodes(root->left) + countNodes(root->right); 
    }
};