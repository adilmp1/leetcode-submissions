    int countPrimes(int n) 
    {
        vector<bool>a (n+1,false);
        a[1]=true;
        for(int i=2;i*i<=n;i++)
        {
            if(a[i]==false)
            {
                for(int j=i*i;j<=n;j+=i)
                {
                    a[j]=true;
                }
            }
        }
        int count=0;
        for(int i=1;i<n;i++)
        {
            if(a[i]==false)
            {
                count++;
            }
        }
        return count;
    }
