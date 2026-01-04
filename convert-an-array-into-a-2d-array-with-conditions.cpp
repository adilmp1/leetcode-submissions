    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int,int> mp;
        int max_freq=0;
        for(auto i:nums)
        {
            mp[i]++;
            max_freq = max(max_freq,mp[i]);
        }
        vector<vector<int>> ans(max_freq);
        for(auto & pair:mp) for(int i=0;i<pair.second;i++) ans[i].push_back(pair.first);
        return ans;
    }
