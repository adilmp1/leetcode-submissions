    bool isValid(string s)
    {
        if(s.size()==2 and s[0]=='0') return false;
        int val=stoi(s);
        return (val>0 and val<=26);
    }
    int numDecodings(string s) 
    {
        int n=s.size();
        vector<int> dp(n,0);
        vector<int> sing(n,0);
        vector<int> dub(n,0);
        if(s[0]=='0') return 0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='0' and (s[i-1]!='1' and s[i-1]!='2')) return 0;
            if(s[i]!='0') sing[i]=1;
            if(i!=n-1)
            {
                if(isValid(s.substr(i,2)))
                {
                    dub[i+1]=1;
                }
            }
        }
        dp[0]=sing[0];
        if(s.size()==1) return dp[n-1];
        if(sing[1] and dub[1])
        {
            dp[1]=2;
        }
        else if(sing[1] or dub[1])
        {
            dp[1]=1;
        }
        for(int i=2;i<n;i++)
        {
            if(sing[i] and dub[i])
            {
                dp[i]=dp[i-1]+dp[i-2];
            }
            else if(sing[i] or dub[i])
            {
                if(s[i]=='0')
                {
                    dp[i]=dp[i-2];
                }
                else
                {
                    dp[i]=dp[i-1];
                }
            }
        }
        return dp[n-1];
    }
