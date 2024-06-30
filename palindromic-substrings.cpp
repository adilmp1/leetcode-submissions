    int countSubstrings(string s) 
    {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        int count=0;
        for(int i=0;i<n;i++) 
        {
            dp[i][i]=1;
            count+=dp[i][i];
        }
        for(int i=0;i<n-1;i++) 
        {
            dp[i][i+1]=(s[i]==s[i+1]);
            count+=dp[i][i+1];
        }
        
        for(int i=2;i<n;i++)
        {
            for(int j=0;j<n-i;j++)
            {
                if(s[j]==s[j+i])
                {
                    dp[j][j+i]=dp[j+1][j+i-1];
                    count+=dp[j][j+i];    
                }
            }
        }
        return count;
    }
