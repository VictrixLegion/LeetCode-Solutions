void dfs(TreeNode* leftNode, TreeNode* rightNode, int level) {
    if (!leftNode || !rightNode) return;
    if (level % 2 != 0) {swap(leftNode->val, rightNode->val);}
    dfs(leftNode->left, rightNode->right, level+1);
    dfs(leftNode->right, rightNode->left, level+1);
    }

    TreeNode* reverseOddLevels(TreeNode* root) {
    if (!root) return nullptr;
    dfs(root->left, root->right, 1);
    return root;
    }
