    vector<int> arrayRankTransform(vector<int>& a) 
    {
        vector<int> v;
        for(auto i:a) v.push_back(i);
        sort(v.begin(),v.end());    
        int idx=1;
        unordered_map<int,int> mp;
        for(int i=0;i<v.size();i++)
        {
            if(!mp.count(v[i])) 
            {
                mp[v[i]]=idx++;
            }
        }
        vector<int> ans;
        for(int i=0;i<a.size();i++)
        {
            ans.push_back(mp[a[i]]);
        }
        return ans;
    }
