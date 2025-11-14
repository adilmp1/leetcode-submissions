    int sumNumbers(TreeNode* root,int num=0)
    {
        int ans=0;
        if(!root) return 0;
        num*=10;
        num+=root->val;
        ans+=sumNumbers(root->left,num);
        if(!root->left and !root->right) return num;
        ans+=sumNumbers(root->right,num);
        return ans;
    }
