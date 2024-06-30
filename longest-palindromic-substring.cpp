string longestPalindrome(string s)
{
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    int l=0,r=0;
    for(int i=0;i<n;i++) 
    {
        dp[i][i]=1;
        if(dp[i][i])
        {
            l=i;r=i;
        }
    }
    for(int i=0;i<n-1;i++) 
    {
        dp[i][i+1]=(s[i]==s[i+1]);
        if(dp[i][i+1])
        {
            l=i;r=i+1;
        }
    }
    
    for(int i=2;i<n;i++)
    {
        for(int j=0;j<n-i;j++)
        {
            if(s[j]==s[j+i])
            {
                dp[j][j+i]=dp[j+1][j+i-1];
                if(dp[j][j+i])
                {
                    l=j;r=j+i;
                }
            }
        }
    }
    return s.substr(l,r-l+1);
}
