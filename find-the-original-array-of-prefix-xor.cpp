    vector<int> findArray(vector<int>& a) 
    {
        vector<int> ans;
        ans.push_back(a[0]);
        for(int i=0;i<a.size()-1;i++) ans.push_back(a[i]^a[i+1]);
        return ans;
    }
