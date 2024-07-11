    vector<int> ans;
    unordered_map<int,int> mp;
    void rightSideViewHelper(TreeNode * root, int pos)
    {
        if(root==NULL) return;
        if(mp.find(pos)==mp.end())
        {
            mp[pos]=1;
            ans.push_back(root->val);
        }
        rightSideViewHelper(root->right,pos+1);
        rightSideViewHelper(root->left,pos+1);
    }   
    vector<int> rightSideView(TreeNode* root) 
    {
        rightSideViewHelper(root,0);
        return ans;
    }
