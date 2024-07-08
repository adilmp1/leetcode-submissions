    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) 
    {
        using Pair = pair<int,vector<int>>;
        auto compare = [](const Pair&a,const Pair &b){
            return a.first>b.first;
        };
        priority_queue<Pair, vector<Pair>, decltype(compare)> pq(compare);
        vector<vector<int>> ans;
        for(vector<int> a:points)
        {
            int dist = a[0]*a[0]+a[1]*a[1];
            pq.push({dist,{a[0],a[1]}});
        }
        while(k--)
        {
            auto au = pq.top();
            ans.push_back({au.second[0],au.second[1]});
            pq.pop();
        }
        return ans;
    }
