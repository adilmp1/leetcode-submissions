    int missingNumber(vector<int>& a) 
    {
        int n = a.size();
        int ans = n*(n+1);
        ans/=2;
        for(int i:a) ans-=i;
        return ans;
    }
