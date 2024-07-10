    vector<int> topKFrequent(vector<int>& a, int k) 
    {
        vector<int> ans;
        unordered_map<int,int> mp;
        for(int i:a) mp[i]++;
        priority_queue<pair<int,int>> pq;
        for(auto & pair:mp)
        {
            pq.push({pair.second,pair.first});
        }
        while(k--)
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
