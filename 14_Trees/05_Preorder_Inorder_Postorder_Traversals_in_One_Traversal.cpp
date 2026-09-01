/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/
vector<vector<int>> getTreeTraversal(TreeNode *root){
    // Write your code here.
    vector<vector<int>>ans;
    if(root == NULL) return ans;
    vector<int>pre;
    vector<int>ino;
    vector<int>post;
    stack<pair<TreeNode*, int>>s;
    s.push({root, 1});
    while(!s.empty()){
        auto it = s.top();
        s.pop();

        // State 1 -> Preorder
        if (it.second == 1) {

            pre.push_back(it.first->data);

            it.second++;
            s.push(it);

            if (it.first->left)
                s.push({it.first->left, 1});
        }

        // State 2 -> Inorder
        else if (it.second == 2) {

            ino.push_back(it.first->data);

            it.second++;
            s.push(it);

            if (it.first->right)
                s.push({it.first->right, 1});
        }

        // State 3 -> Postorder
        else {

            post.push_back(it.first->data);
        }
    }
    ans.push_back(ino);
    ans.push_back(pre);
    ans.push_back(post);
    return ans;
}