    int minimumIndex(vector<int>& a) 
    {
        unordered_map<int,int> mp1;
        unordered_map<int,int> mp2;
        for(auto i:a) mp1[i]++;
        int ans=-1;
        for(int i=0;i<a.size();i++)
        {
            int val = a[i];

            mp2[val]++;
            mp1[val]--;

            if(mp2[val]>((i+1)/2) and mp1[val]>((a.size()-i-1)/2))
            {
                ans=i;
                break;
            }
            
        }
        return ans;
    }
