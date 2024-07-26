    int maximumPopulation(vector<vector<int>>& a) 
    {
        int minY=INT_MAX;
        int maxY=INT_MIN;
        unordered_map<int,int> born;
        unordered_map<int,int> dead;
        for(int i=0;i<a.size();i++)
        {
            for(int j=0;j<a[0].size();j++)
            {
                if(j==0) born[a[i][j]]++;
                else dead[a[i][j]]++;
                minY=min(minY,a[i][j]);
                maxY=max(maxY,a[i][j]);
            }
        }
        int ans=0;
        int year=0;
        int prev=INT_MIN;
        for(int i=minY;i<=maxY;i++)
        {
            ans+=born[i];
            ans-=dead[i];
            if(ans>prev)
            {
                prev=ans;
                year=i;
            }
        }
        return year;
    }
