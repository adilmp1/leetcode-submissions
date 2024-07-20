bool isInterleaveHelper(string s1,string s2,string s3,int l1,int l2,string curr,vector<vector<int>>& dp)
{
    if(l1>=s1.size() and l2>=s2.size()) return true;
    if(dp[l1][l2]!=-1) return dp[l1][l2];
    bool b1=false,b2=false;
    if(l1<s1.size() and s1[l1]==s3[l1+l2])
    {
        b1 = isInterleaveHelper(s1,s2,s3,l1+1,l2,curr,dp);
    }
    if(l2<s2.size() and s2[l2]==s3[l1+l2])
    {
        b2 = isInterleaveHelper(s1,s2,s3,l1,l2+1,curr,dp);
    }
    dp[l1][l2]=b1 or b2;
    return dp[l1][l2];
}
bool isInterleave(string s1, string s2, string s3)
{
    if(s1.size()+s2.size()!=s3.size()) return false;
    int m = s1.size();
    int n = s2.size();
    vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
    return isInterleaveHelper(s1,s2,s3,0,0,"",dp);
}
