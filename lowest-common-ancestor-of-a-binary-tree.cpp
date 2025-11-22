    #define Node TreeNode
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root or root==p or root==q) return root;
        Node * left = lowestCommonAncestor(root->left,p,q);
        Node * right = lowestCommonAncestor(root->right,p,q);
        if(left and right) return root;
        return left ? left : right;
    }
