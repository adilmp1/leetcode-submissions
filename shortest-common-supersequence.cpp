string shortestCommonSupersequence(string a,string b)
{
    int m = a.size();
    int n = b.size();
    vector<vector<int>> dp(m+1,vector<int>(n+1,0));
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(a[i-1]==b[j-1])
            {
                dp[i][j] = 1+dp[i-1][j-1];
            }
            else
            {
                dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
            }
        }
    }

    string s = "";
    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (a[i - 1] == b[j - 1]) 
        { 
            s = a[i - 1] + s; 
            i--;
            j--;
        } 
        else if (dp[i - 1][j] > dp[i][j - 1]) i--; 
        else j--; 
    }
    string ans;
    int x=0,y=0;
    for(auto ch:s)
    {
        while(a[x]!=ch) ans+=a[x++];
        while(b[y]!=ch) ans+=b[y++];

        ans+=ch;
        x++;
        y++;
    }
    ans+=a.substr(x);
    ans+=b.substr(y);
    return ans;
}
