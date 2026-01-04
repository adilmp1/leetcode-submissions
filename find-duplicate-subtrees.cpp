    #define Node TreeNode
    vector<Node*> ans;
    unordered_map<string,int> mp;
    string solve(Node * root)
    {
        if(!root) return "#";
        string order = "" + to_string(root->val)+"->";
        order+=solve(root->left);
        order+=solve(root->right);
        mp[order]++;
        if(mp[order]==2) ans.push_back(root);
        return order;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        solve(root);
        return ans;
    }
