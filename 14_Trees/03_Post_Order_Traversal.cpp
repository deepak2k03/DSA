void f(TreeNode *root, vector<int>&v){
    if(root==NULL) return;
    f(root->left,v);
    f(root->right,v);
    v.push_back(root->val); 
}
