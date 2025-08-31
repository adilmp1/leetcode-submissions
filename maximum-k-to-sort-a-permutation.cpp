    int sortPermutation(vector<int>& a) {
        if(a[0]!=0) return 0;
        int ans=-1;
        for(int i=0;i<a.size();i++)
        {
            if(a[i]!=i) 
            {
                if(ans==-1) ans = a[i];
                else ans&=a[i];
            }
        }
        if(ans==-1) return 0;
        return ans;
    }
