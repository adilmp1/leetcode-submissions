    #define Node TreeNode
    int ans = INT_MIN;
    int solve(Node * root,int val)
    {   
        if(!root or root->val!=val) return 0;
        return 1+max(solve(root->left,val),solve(root->right,val));
    }
    void dfs(Node * root)
    {
        if(!root) return;
        ans = max(ans,1+solve(root->left,root->val)+solve(root->right,root->val));
        dfs(root->left);
        dfs(root->right);
    }
    int longestUnivaluePath(TreeNode* root) {
        if(!root) return 0;
        dfs(root);
        return ans-1;

    }
