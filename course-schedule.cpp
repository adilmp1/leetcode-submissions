bool dfs(int idx,vector<bool>& vis,unordered_map<int,vector<int>>& mp,vector<bool> dp)
{
    if(vis[idx]) 
    {
        return !dp[idx]; 
    }
    vis[idx]=true;
    dp[idx]=true;
    if(mp.find(idx)!=mp.end())
    {
        for(int i=0;i<mp[idx].size();i++)
        {
            if(!dfs(mp[idx][i],vis,mp,dp)) return false;
        }
    }
    return true;
}

bool canFinish(int numCourses, vector<vector<int>> &a)
{
    unordered_map<int,vector<int>> mp;
    for(auto i:a)
    {
        mp[i[1]].push_back(i[0]);
    }
    vector<bool> vis(numCourses,false);
    for(int i=0;i<numCourses;i++)
    {
        if(!vis[i])
        {
            vector<bool> dp(numCourses,false);
            if(!dfs(i,vis,mp,dp))
            {
                return false;
            }
        }
    }
    return true;
}
