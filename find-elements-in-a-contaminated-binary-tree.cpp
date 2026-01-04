    unordered_set<int> s;
    #define Node TreeNode
    void build(Node * root)
    {
        if(!root) return;
        s.insert(root->val);
        if(root->left) root->left->val=(2*(root->val)+1);
        if(root->right) root->right->val=(2*(root->val)+2);
        build(root->left);
        build(root->right);
    }
    
    FindElements(TreeNode* root) {
        root->val=0;
        build(root);
    }
    
    bool find(int target) {
        return s.find(target)!=s.end();
    }
