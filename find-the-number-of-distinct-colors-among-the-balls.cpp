vector<int> queryResults(int limit, vector<vector<int>> &queries)
{
    vector<int> ans;
    unordered_map<int,int> mp;
    unordered_map<int,int> count;
    for(auto & v:queries)
    {
        if(!mp.count(v[0]))
        {
            mp[v[0]]=v[1];
            count[v[1]]++;
        }
        else
        {
            if(mp[v[0]]==v[1]) 
            {
                ans.push_back(count.size());
                continue;
            }
            int key = v[0];
            int value = mp[key];

            mp[key] = v[1];

            count[v[1]]++;
            count[value]--;
            if(count[value]<=0)
            {
                count.erase(value);
            }
        }
        ans.push_back(count.size());
    }
    return ans;
}
