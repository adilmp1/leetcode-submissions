    #define Node TreeNode
    vector<Node*> sus;
    Node * prev_node = nullptr;
    int prev_value=INT_MIN;
    void inOrder(Node * root)
    {
        if(!root) return;
        inOrder(root->left);
        if(root->val < prev_value) 
        {
            if(sus.empty() or !sus.empty() and sus.back()!=prev_node) sus.push_back(prev_node);
            sus.push_back(root);
        }
        prev_node = root;
        prev_value=root->val;
        inOrder(root->right);
    }
    void recoverTree(TreeNode* root) {
        inOrder(root);
        set<int> s;
        for(auto & node:sus) s.insert(node->val);
        int idx=0;
        for(auto & val:s)
        {
            sus[idx++]->val = val;
        }        
    }
