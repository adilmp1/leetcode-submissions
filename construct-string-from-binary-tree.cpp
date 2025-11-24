    #define Node TreeNode
    string tree2str(TreeNode* root) {
        if(!root) return "";
        string ans="";
        ans+=to_string(root->val);
        string left = tree2str(root->left);
        string right = tree2str(root->right);
        
        if (!right.empty()) {
            ans += "(" + left + ")";
            ans += "(" + right + ")";
        } 
        else if (!left.empty()) {
            ans += "(" + left + ")";
        }
        return ans;
    }
