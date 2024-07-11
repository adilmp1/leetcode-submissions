    int count=0;
    int ans=-1;
    void kthSmallestHelper(TreeNode* root, int k) 
    {
        if(root==NULL) return;
        kthSmallest(root->left,k);
        count++;
        if(count==k) 
        {
            ans=root->val;
            return;
        }
        kthSmallest(root->right,k);
    }
    int kthSmallest(TreeNode * root, int k)
    {
        kthSmallestHelper(root,k);
        return ans;
    }
