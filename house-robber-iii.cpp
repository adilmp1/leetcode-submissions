    #define Node TreeNode
    pair<int,int> helper(Node * root)
    {
        if(!root) return {0,0};
        pair<int,int> leftOptions = helper(root->left);
        pair<int,int> rightOptions = helper(root->right);

        pair<int,int> options; 
        options.first = root->val + leftOptions.second + rightOptions.second;
        options.second = max(leftOptions.first,leftOptions.second)+max(rightOptions.first,rightOptions.second);
      
        return options;
    }
    int rob(TreeNode* root) 
    {
        pair<int,int> options = helper(root);
        return max(options.first,options.second);    
    }
