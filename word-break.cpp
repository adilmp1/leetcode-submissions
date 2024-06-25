bool wordBreakHelper(string s,int l, unordered_map<string, int> &mp,vector<int>& dp)
{   

    if(dp[l]!=-1) return dp[l];
    if(l==s.size()) return dp[l]=true;
    for(int i=l+1;i<=s.size();i++)
    {
        if(mp.find(s.substr(l,i-l))!=mp.end() and wordBreakHelper(s,i,mp,dp)) 
            return dp[l]=true; 
    }
    return dp[l]=false;
}
bool wordBreak(string s, vector<string> &wordDict)
{
    unordered_map<string, int> mp;
    for (string s : wordDict)
    {
        mp[s]++;
    }
    int n = s.size();
    vector<int> dp(n+1,-1);

    return wordBreakHelper(s,0,mp,dp);
}
