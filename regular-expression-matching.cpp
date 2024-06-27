    bool isMatchHelper(string s,string p, int i,int j,int m,int n,vector<vector<int>>& dp)
    {   
        if(dp[i][j]!=-1) return dp[i][j];
        if(i>=m and j>=n) return dp[i][j]=true;
        if(j>=n) return false;

        bool match = (i<m) and (s[i]==p[j] or p[j]=='.');
        
        if( (j+1)<n and p[j+1]=='*')
        {
            return dp[i][j]=(isMatchHelper(s,p,i,j+2,m,n,dp) or (match and isMatchHelper(s,p,i+1,j,m,n,dp)));
        }
        if(match)
        {
            return dp[i][j]=isMatchHelper(s,p,i+1,j+1,m,n,dp);
        }
        return dp[i][j]=false;
    }
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        return isMatchHelper(s,p,0,0,m,n,dp);
    }
