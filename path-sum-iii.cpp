    #define Node TreeNode
    int ans=0;
    void solve(Node * root,long long target)
    {
        if(!root) return;
        if(root->val == target) ans++;
        solve(root->left,target-root->val);
        solve(root->right,target-root->val);
    }
    int pathSum(TreeNode* root, int target) {
        if(!root) return 0;
        solve(root,target);
        pathSum(root->left,target);
        pathSum(root->right,target);
        return ans;
    }
