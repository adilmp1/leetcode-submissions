    long minimum(node * root)
    {
        if(root==NULL) return LONG_MAX;
        return min({(long)root->val,minimum(root->left),minimum(root->right)});
    }
    long maximum(node * root)
    {
        if(root==NULL) return LONG_MIN;
        return max({(long)root->val,maximum(root->left),maximum(root->right)});
    }
    bool isValidBST(TreeNode* root) 
    {
        if(root==NULL) return true;
        if(root->left==NULL and root->right==NULL) return true;
        cout<<maximum(root->left)<<endl;
        cout<<minimum(root->right);
        if(root->val <= maximum(root->left)) return false;
        if(root->val >= minimum(root->right)) return false;
        return (isValidBST(root->left) and isValidBST(root->right));
    }
