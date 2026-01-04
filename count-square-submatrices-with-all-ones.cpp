    int countSquares(vector<vector<int>>& a) {
        int ans = 0;
        int m = a.size();
        int n = a[0].size();
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                if(a[i][j]) a[i][j] = 1+min({a[i-1][j],a[i][j-1],a[i-1][j-1]});
                ans+=a[i][j];
            }
        }
        for(int i=0;i<n;i++) ans+=a[0][i];
        for(int i=0;i<m;i++) ans+=a[i][0];
        return ans-a[0][0];
    }
