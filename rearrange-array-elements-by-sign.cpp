    vector<int> rearrangeArray(vector<int>& a) 
    {
        int n = a.size();
        vector<int> ans(n,0);
        int idx1 = 0;
        int idx2 = 1;
        for(auto i:a)
        {
            if(i<0)
            {
                ans[idx2]=i;
                idx2+=2;
            }
            else
            {
                ans[idx1]=i;
                idx1+=2;
            }
        }
        return ans;
    }
