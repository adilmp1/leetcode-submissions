    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if(!root) return root;
        root->left = removeLeafNodes(root->left,target);
        root->right = removeLeafNodes(root->right,target);
        if(!root->left and !root->right and root->val==target) return nullptr;
        return root;
    }
