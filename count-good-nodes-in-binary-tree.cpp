    int cnt=0;
    void preOrder(TreeNode * root,int maxi)
    {
        if(root)
        {
            if(root->val>=maxi) cnt++;
            preOrder(root->left,max(maxi,root->val));
            preOrder(root->right,max(maxi,root->val));
        }
    }
    int goodNodes(TreeNode* root) 
    {
        preOrder(root,INT_MIN);
        return cnt;
    }
