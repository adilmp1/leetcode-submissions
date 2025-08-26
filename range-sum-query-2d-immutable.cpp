    vector<vector<int>> a;
    int m,n;
    bool isValid(int m,int n,int r,int c)
    {
        return (r>=0 and c>=0 and r<m and c<n);
    }
    NumMatrix(vector<vector<int>>& matrix) {
        a = matrix;        
        m = a.size();
        n = a[0].size();
        if(n>1) for(int i=1;i<n;i++) a[0][i]+=a[0][i-1];
        if(m>1) for(int i=1;i<m;i++) a[i][0]+=a[i-1][0];
        if(m>1 and n>1)
        {
            for(int i=1;i<m;i++)
            {
                for(int j=1;j<n;j++)
                {
                    a[i][j]+=a[i-1][j];
                    a[i][j]+=a[i][j-1];
                    a[i][j]-=a[i-1][j-1];
                }
            }
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout<<a[i][j]<<"\t";
            }
            cout<<endl;
        }
    }
    int sumRegion(int r1, int c1, int r2, int c2) 
    {
        int ans=0;
        ans+=a[r2][c2];

        if(isValid(m,n,r2,c1-1)) ans-=a[r2][c1-1];
        if(isValid(m,n,r1-1,c2)) ans-=a[r1-1][c2];
        if(isValid(m,n,r1-1,c1-1)) ans+=a[r1-1][c1-1];
        
        return ans;

    }
