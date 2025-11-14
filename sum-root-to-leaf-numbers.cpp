    int ans=0;
    void sumNumbersHelper(TreeNode* root,int num=0)
    {
        if(!root) return;
        num*=10;
        num+=root->val;
        sumNumbersHelper(root->left,num);
        if(!root->left and !root->right)
        {
            ans+=num;
            return;
        }
        sumNumbersHelper(root->right,num);

    }

    int sumNumbers(TreeNode* root,int num=0) {
        sumNumbersHelper(root);
        return ans;
    }
