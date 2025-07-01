void f(TreeNode *root, vector<int>&v){
    if(root==NULL) return;
    f(root->left,v);
    v.push_back(root->val); 
    f(root->right,v);
}
