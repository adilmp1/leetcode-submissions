    int minDominoRotations(vector<int>& a, vector<int>& b) 
    {
        int ans = INT_MAX;
        int n = a.size();
        for(int i=1;i<=6;i++)
        {
            bool flag=true;
            int cnt1=0;
            int cnt2=0;
            for(int j=0;j<n;j++)
            {
                if(a[j]!=i and b[j]!=i)
                {
                    flag=false;
                }
                else
                {
                    cnt1+=(a[j]==i);
                    cnt2+=(b[j]==i);
                }
            }

            if(flag)
            {
                ans = min(ans,min(cnt1,n-cnt1));
                ans = min(ans,min(cnt2,n-cnt2));
            }
        }
        if(ans==INT_MAX) return -1;
        return ans;
    }
