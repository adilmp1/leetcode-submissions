    int maxProfit(vector<int>& a) 
    {
        int n = a.size();
        int mini = a[0];
        int maxi = 0;
        for(int i=0;i<n;i++)
        {
            mini = min(mini,a[i]);
            maxi = max(maxi,a[i]-mini);
        }
        return maxi;
    }
