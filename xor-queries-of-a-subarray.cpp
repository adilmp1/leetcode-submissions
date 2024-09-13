    vector<int> xorQueries(vector<int>& a, vector<vector<int>>& queries) 
    {
        int n = a.size();
        vector<int> pre;
        vector<int> ans;
        int cur=0;
        for(auto i:a)
        {
            cur^=i;
            pre.push_back(cur);
        } 
        for(auto pair:queries)
        {
            int val = 0;
            val = pre[pair[1]];
            if(pair[0]) val^=pre[pair[0]-1];
            ans.push_back(val);
        }
        return ans;
    }
