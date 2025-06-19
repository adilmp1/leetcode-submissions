    int partitionArray(vector<int>& a, int k) 
    {
        sort(a.begin(),a.end());
        int ans=1;
        int start = a[0];
        int end=-1;
        for(int i=0;i<a.size();i++)
        {
            end = a[i];

            if(end-start > k)
            {
                ans++;
                start = a[i];
            }
        }
        return ans;
    }
