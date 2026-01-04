    long long getDescentPeriods(vector<int>& a) {
        long long ans=0;
        ans+=a.size();
        for(int i=1;i<a.size();i++)
        {
            long long count=1;
            while(i<a.size() and a[i]==a[i-1]-1)
            {
                i++;
                count++;
            }
            if(count>1) 
            {
                long long add = count*count;
                add+=count;
                add/=2;
                add-=count;
                ans+=add;
            }
        }
        return ans;
    }
