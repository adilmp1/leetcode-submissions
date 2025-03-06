    vector<vector<int>> onesMinusZeros(vector<vector<int>>& a) 
    {
        int m = a.size();
        int n = a[0].size();
        vector<int> row_ones(m,0);
        vector<int> col_ones(n,0);
        for(int i=0;i<m;i++)
        {
            int c1=0;
            for(int j=0;j<n;j++)
            {
                c1+=a[i][j];
            }
            row_ones[i]=c1;
        }
        for(int i=0;i<n;i++)
        {
            int c1=0;
            for(int j=0;j<m;j++)
            {
                c1+=a[j][i];
            }
            col_ones[i]=c1;
        }
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                a[i][j] = row_ones[i]+col_ones[j]-m-n+row_ones[i]+col_ones[j];
            }
        }
        return a;
    }
