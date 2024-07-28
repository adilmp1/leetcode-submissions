    void setZeroes(vector<vector<int>>& a) 
    {
        unordered_map<int,int> rows;    
        unordered_map<int,int> cols;    
        for(int i=0;i<a.size();i++)
        {
            for(int j=0;j<a[0].size();j++)
            {
                if(a[i][j]==0)
                {
                    rows[i]=1;
                    cols[j]=1;
                }
            }
        }
        for(auto & pair:rows)
        {
            for(int i=0;i<a[0].size();i++)
            {
                a[pair.first][i]=0;
            }
        }
        for(auto & pair:cols)
        {
            for(int i=0;i<a.size();i++)
            {
                a[i][pair.first]=0;
            }
        }
    }
