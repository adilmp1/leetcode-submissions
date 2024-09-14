    int longestSubarray(vector<int>& a) 
    {
        int maxi = 0;
        for(auto i:a) maxi=max(maxi,i);
        int ans=0;
        int cnt=0;
        for(int i=0;i<a.size();i++)
        {
            if(a[i]==maxi) cnt++;
            else cnt=0;
            ans=max(cnt,ans); 
        }
        return ans;
    }
