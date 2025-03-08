    int minimumRecolors(string s, int k) 
    {
        int ans = INT_MAX;
        int val=0;
        for(int i=0;i<k;i++)
        {
            if(s[i]=='W') val++;
        }
        ans = min(ans,val);
        int idx=0;
        for(int i=k;i<s.size();i++)
        {
            if(s[idx]=='W' and s[i]=='B') val--;
            else if(s[idx]=='B' and s[i]=='W') val++;
            idx++;
            ans = min(ans,val);
        }
        return ans;
    }
