    int findContentChildren(vector<int>& g, vector<int>& s) 
    {
        int ans=0;
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int i=0;
        int j=0;
        while(i<g.size() and j<s.size())
        {
            if(g[i]<=s[j])
            {
                ans++;
                i++;j++;
            }
            else 
            {
                j++;
            }
        }
        return ans;
    }
