    vector<vector<int>> generate(int n) 
    {
        vector<vector<int>> ans;
        ans.push_back({1});
        if(n==1) return ans;
        ans.push_back({1,1});
        if(n==2) return ans;
        for(int size=3;size<=n;size++)
        {
            vector<int> temp = ans.back();
            vector<int> v;
            for(int i=0;i<size;i++)
            {
                if(i==0 or i==size-1) v.push_back(1);
                else v.push_back(temp[i]+temp[i-1]); 
            }
            ans.push_back(v);
        }
        return ans;
    }
