    vector<vector<int>> ans;
    void helper(int n,int k,vector<int> temp,int idx)
    {
        if(temp.size()==k) ans.push_back(temp);
        for(int i=idx;i<=n;i++)
        {
            temp.push_back(i);
            helper(n,k,temp,i+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        helper(n,k,{},1);
        return ans;
    }
