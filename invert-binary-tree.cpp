    TreeNode* invertTree(TreeNode* root) 
    {
        if(root==NULL) return NULL;
        TreeNode* temp = root->left;
        root->left=root->right;
        root->right=temp;
        invertTree(root->right);
        invertTree(root->left);
        return root;  
    }
