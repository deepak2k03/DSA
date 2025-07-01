void f(TreeNode *root, vector<int>&v){
    if(root==NULL) return;
    v.push_back(root->val); 
    f(root->left,v);
    f(root->right,v);
}
