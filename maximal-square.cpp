    int maximalSquare(vector<vector<char>>& matrix) {
        int ans = 0;
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> a(m,vector<int>(n,0));
        bool flag=false;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j]=='1') 
                {
                    flag=true;
                    a[i][j]=1;
                }
            }
        }
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                if(a[i][j])
                {
                    a[i][j] = 1+min({a[i-1][j],a[i][j-1],a[i-1][j-1]});
                    ans = max(ans,a[i][j]);
                }
            }
        }
        ans*=ans;
        if(!ans and flag) return 1;
        return ans; 
    }
