    #define Node TreeNode
    int ans=0;
    pair<int,int> solve(Node * root)
    {
        if(!root) return {0,0};
        int sum=root->val;
        pair<int,int> left = solve(root->left);
        pair<int,int> right = solve(root->right);
        sum+=left.second;
        sum+=right.second;
        int count = 1+left.first+right.first;
        int avg = sum/count;
        ans+=(avg==root->val);
        return {1+left.first+right.first,sum};
    }
    int averageOfSubtree(TreeNode* root) {
        solve(root);
        return ans;
    }
