int best = 0;

int height(TreeNode* node) {
    if (node == nullptr) return 0;

    int first = 0, second = 0;

    for (TreeNode* child : node->children) {
        int h = height(child);

        if (h > first) {
            second = first;
            first = h;
        } else if (h > second) {
            second = h;
        }
    }

    best = max(best, first + second);

    return first + 1;
}

int solve(TreeNode* root) {
    best = 0;
    height(root);
    return best;
}