class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        unsigned long long ans = 0;
        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 0});
        while (!q.empty()) {
            int size = q.size();
            unsigned long long mn = q.front().second;
            unsigned long long first = 0, last = 0;
            for (int i = 0; i < size; i++) {
                unsigned long long cur = q.front().second - mn; 
                TreeNode* node = q.front().first;
                q.pop();
                if (i == 0) first = cur;
                if (i == size - 1) last = cur;
                if (node->left) q.push({node->left, cur * 2 + 1});
                if (node->right) q.push({node->right, cur * 2 + 2});
            }
            ans = max(ans, last - first + 1);
        }
        return (int)ans;
    }
};
