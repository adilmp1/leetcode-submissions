// Greedy optimized solution
    bool checkValidString(string s) 
    {
        int left=0;
        int secondLeft=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
            {
                left++;
                secondLeft++;
            }
            else if(s[i]==')')
            {
                left--;
                secondLeft--;
            }
            else
            {
                left++;
                secondLeft--;
            }
            if(left<0) return false;
            if(secondLeft<0) secondLeft=0;
        }
        return (secondLeft==0);
    }

// My Solution with DP
    bool checkValidStringHelper(string s,int curr,int val,int n,vector<vector<int>>& dp)
    {
        if(curr>=n) return (val==0);
        if(val<0) return false;
        if (dp[curr][val] != -1) return dp[curr][val];
        if(s[curr]=='(') return dp[curr][val]=checkValidStringHelper(s,curr+1,val+1,n,dp);
        if(s[curr]==')') return dp[curr][val]=checkValidStringHelper(s,curr+1,val-1,n,dp);
        bool b1 = checkValidStringHelper(s,curr+1,val+1,n,dp);
        bool b2 = checkValidStringHelper(s,curr+1,val-1,n,dp);
        bool b3 = checkValidStringHelper(s,curr+1,val,n,dp);
        return dp[curr][val]=(b1 or b2 or b3);
    }
    bool checkValidString(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return checkValidStringHelper(s,0,0,n,dp);
    }
