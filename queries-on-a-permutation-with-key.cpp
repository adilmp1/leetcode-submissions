    vector<int> processQueries(vector<int>& queries, int m) 
    {
        vector<int> perm;
        for(int i=1;i<=m;i++) perm.push_back(i);
        for(int i=0;i<queries.size();i++)
        {
            auto it = find(perm.begin(),perm.end(),queries[i]);
            int idx = distance(perm.begin(),it);
            perm.erase(it);
            perm.insert(perm.begin(),queries[i]);
            queries[i]=idx;
        }
        return queries;
    }
