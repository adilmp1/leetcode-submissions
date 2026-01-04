    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int,vector<int>> mp;
        for(int i=0;i<groupSizes.size();i++)
        {
            mp[groupSizes[i]].push_back(i);
        }
        vector<vector<int>> ans;
        for(auto & pair:mp)
        {
            int size = pair.first; 
            vector<int> & a = pair.second;
            int cnt=0;
            vector<int> temp;
            for(int i=0;i<a.size();i++)
            {
                temp.push_back(a[i]);
                cnt++;
                cnt%=size;
                if(!cnt)
                {
                    ans.push_back(temp);
                    temp.clear();
                }
            }
        }
        return ans;
    }
