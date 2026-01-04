    #define Node TreeNode
    int ans = 0;
    int solve(Node * root)
    {
        if(!root) return 0;
        int leftWants = solve(root->left);
        int rightWants = solve(root->right);
        ans+=abs(leftWants)+abs(rightWants);
        return (root->val+leftWants+rightWants-1);

    }
    int distributeCoins(TreeNode* root) {
        solve(root);
        return ans;
    }
