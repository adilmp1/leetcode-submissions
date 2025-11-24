    #define Node TreeNode
    int max_freq = 0;
    unordered_map<int,int> mp;
    int sum(Node * root)
    {
        if(!root) return 0;
        int subTreeSum = root->val;
        subTreeSum+=sum(root->left);
        subTreeSum+=sum(root->right);
        mp[subTreeSum]++;
        max_freq = max(max_freq,mp[subTreeSum]);
        return (subTreeSum);
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        sum(root);
        vector<int> ans;
        for(auto & pair:mp)  if(pair.second==max_freq) ans.push_back(pair.first);
        return ans;
    }
