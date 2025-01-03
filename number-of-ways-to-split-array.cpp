    int waysToSplitArray(vector<int>& a) 
    {
        long long int total_sum=0;
        for(auto val:a) total_sum+=val;
        long long int curr_sum=0;
        int ans=0;
        for(int i=0;i<a.size()-1;i++) 
        {
            curr_sum+=a[i];
            if(curr_sum>=(total_sum-curr_sum)) ans++;
        }
        return ans;
    }
