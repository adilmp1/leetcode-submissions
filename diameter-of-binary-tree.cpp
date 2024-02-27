    int height(TreeNode * root)
    {
        if(root==NULL) return 0;
        return 1+max(height(root->left),height(root->right));
    }
    int diameterOfBinaryTree(TreeNode* root) 
    {
        if(root==NULL) return 0;
        int dia = height(root->left)+height(root->right);
        dia = max({dia,diameterOfBinaryTree(root->left),diameterOfBinaryTree(root->right)});
        return dia;     
    }
