// My Solution using memoization
int numDistinctHelper(string s,string t,int l1,int l2,vector<vector<int>>& dp)
{
    if(l2>t.size()) return 1;
    if(l1>s.size()) return 0;
    int ans=0;
    if(dp[l1][l2]!=-1) return dp[l1][l2];
    if(s[l1]==t[l2]) ans+=numDistinctHelper(s,t,l1+1,l2+1,dp);
    ans+=numDistinctHelper(s,t,l1+1,l2,dp);
    return dp[l1][l2]=ans;
}

int numDistinct(string s, string t)
{
    vector<vector<int>> dp(s.size()+1,vector<int>(t.size()+1,-1));
    return numDistinctHelper(s,t,0,0,dp);
}
