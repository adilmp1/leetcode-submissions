    #define Node TreeNode
    int ans = 0;

    void solve(Node * root,int mini,int maxi)
    {
        if(!root) return;
        ans = max({ans,abs(root->val-mini),abs(root->val-maxi)});
        mini = min(mini,root->val);
        maxi = max(maxi,root->val);
        solve(root->left,mini,maxi);
        solve(root->right,mini,maxi);

    }
    int maxAncestorDiff(TreeNode* root) {
        if(!root) return 0;
        int mini = root->val;
        int maxi = root->val;
        solve(root,mini,maxi);
        return ans;
    }
