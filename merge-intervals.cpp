    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        for(auto pair:intervals)
        {
            if(!ans.empty())
            {
                auto& prev = ans.back();
                if(prev[1]>=pair[0] and prev[1]<=pair[1])
                {
                    prev[1]=pair[1];
                }
                else if(prev[1]>=pair[0] and prev[1]>pair[1])
                {
                    continue;
                }
                else
                {
                    ans.push_back({pair[0],pair[1]});
                }
            }
            else
            {
                ans.push_back({pair[0],pair[1]});
            }
        }     
        return ans;  
    }
