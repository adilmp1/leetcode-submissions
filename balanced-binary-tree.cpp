    int height(TreeNode *root)
    {
        if(!root) return 0;
        return 1+max(height(root->left),height(root->right));
    }
    int balanceFactor(TreeNode *root)
    {
        return abs(height(root->left)-height(root->right));
    }
    bool isBalanced(TreeNode* root) 
    {
        if(!root) return true;
        int bf=balanceFactor(root);
        if(bf!=0 and bf!=1 and bf!=-1) return false; 
        return (isBalanced(root->left) and isBalanced(root->right));
    }
