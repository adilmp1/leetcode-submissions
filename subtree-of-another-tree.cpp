    bool isSameTree(TreeNode* p, TreeNode* q) 
    {
        if(p==NULL and q==NULL) return true;
        if(p==NULL or q==NULL) return false;
        if(p->val!=q->val) return false;
        return (isSameTree(p->left,q->left) and isSameTree(p->right,q->right));
    }
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) 
    {
        if(root==NULL) return false;
        if(isSameTree(root,subRoot)) return true;
        return (isSubtree(root->left,subRoot) or isSubtree(root->right,subRoot));
    }
