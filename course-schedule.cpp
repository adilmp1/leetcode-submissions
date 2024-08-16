// indegree method
bool canFinish(int numCourses, vector<vector<int>> &a)
{
    unordered_map<int,vector<int>> mp;
    unordered_map<int,bool> dp;
    vector<int> indegree(numCourses,0);
    for(auto i:a)
    {
        mp[i[1]].push_back(i[0]);
        indegree[i[0]]++;
    }
    int completed=0;
    queue<int> q;
    for(int i=0;i<numCourses;i++)
    {
        if(!indegree[i])
        {
            q.push(i);
            dp[i]=true;
        }
    }
    while(!q.empty())
    {
        int idx=q.front();q.pop();
        for(auto i:a)
        {
            if(i[1]==idx)
            {
                indegree[i[0]]--;
            }
        }
        for(int i=0;i<numCourses;i++)
        {
            if(!indegree[i] and !dp[i])
            {
                dp[i]=true;
                q.push(i);
            }
        }

    }
    return (dp.size()==numCourses);
}

// recursive dfs method
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
