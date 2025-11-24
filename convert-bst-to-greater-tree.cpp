    #define Node TreeNode
    int rootSum = 0;
    int sum(Node * root)
    {
        if(!root) return 0;
        return root->val+sum(root->left)+sum(root->right);
    }
    void inOrder(Node *& root)
    {
        if(!root) return;
        inOrder(root->left);
        int val = root->val;
        root->val = rootSum;
        rootSum-=val;
        inOrder(root->right);
    }
    TreeNode* convertBST(TreeNode* root) {
        rootSum = sum(root);
        inOrder(root);
        return root;
    }
