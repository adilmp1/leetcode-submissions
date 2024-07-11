    bool found(TreeNode * root,TreeNode* node)
    {
        if(root==NULL) return false;
        if(root==node) return true;
        return (found(root->left,node) or found(root->right,node));
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        if(!root) return root;
        if(root==p or root==q) return root;
        bool b1 = found(root->left,p);
        bool b2 = found(root->left,q);
        if(b1 and b2) return lowestCommonAncestor(root->left,p,q);
        if(!b1 and !b2) return lowestCommonAncestor(root->right,p,q);
        return root;
    }
