    int minimumArea(vector<vector<int>>& a) 
    {
        int top = INT_MAX;
        int bottom = INT_MIN;
        int left = INT_MAX;
        int right = INT_MIN;
        for(int i=0;i<a.size();i++)
        {
            for(int j=0;j<a[0].size();j++)
            {
                if(a[i][j])
                {
                    top = min(top,i);
                    bottom = max(bottom,i);
                    left = min(left,j);
                    right = max(right,j);
                }
            }
        }
        int ans = (bottom-top+1)*(right-left+1);
        return ans;
    }
