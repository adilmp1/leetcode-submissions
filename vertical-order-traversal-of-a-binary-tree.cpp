// high - space complexity
    map<pair<int,int>,multiset<int>> mp;
    void verticalTraversalHelper(TreeNode* root,int row,int col)
    {
        if(root==NULL)
        {
            return;
        }
        mp[{row,col}].insert(root->val);
        verticalTraversalHelper(root->left,row+1,col-1);
        verticalTraversalHelper(root->right,row+1,col+1);

    }
    vector<vector<int>> verticalTraversal(TreeNode* root) 
    {
        map<int,vector<int>> mp2;
        verticalTraversalHelper(root,0,0);
        vector<vector<int>> ans;
        for(auto & pair:mp)
        {
            int col = pair.first.second;
            multiset<int> &values = pair.second;
            for(int i:values) mp2[col].push_back(i);
        }
        for(auto & pair:mp2)
        {
            ans.push_back(pair.second);
        }
        return ans;
    }
