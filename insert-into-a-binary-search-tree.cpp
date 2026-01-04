    #define Node TreeNode
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root) return new Node(val);
        if(root->val > val) root->left = insertIntoBST(root->left,val);
        if(root->val < val) root->right = insertIntoBST(root->right,val);
        return root;
    }
