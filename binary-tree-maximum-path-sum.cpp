    int maxPathSumHelper(TreeNode* root,int &maxi)
    {
        if(!root) return 0;
        int left = maxPathSumHelper(root->left,maxi);
        int right = maxPathSumHelper(root->right,maxi);
        maxi = max(maxi,root->val+left+right);
        return (max(0,root->val+max(left,right)));

    }
    int maxPathSum(TreeNode* root)
    {
        int maxi=INT_MIN;
        maxPathSumHelper(root,maxi);
        return maxi;
    }
