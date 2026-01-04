    #define Node TreeNode
    int maxHeight(Node * root)
    {
        if(!root) return 0;
        return 1+max(maxHeight(root->left),maxHeight(root->right));
    }
    Node * solve(Node * root,int height,int curr)
    {
        if(!root) return root;
        if(curr==height) return root;

        Node * left = solve(root->left,height,curr+1);
        Node * right = solve(root->right,height,curr+1);

        if(left and right) return root;
        return left ? left : right;
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        int height = maxHeight(root);
        return solve(root,height,1);
    }
