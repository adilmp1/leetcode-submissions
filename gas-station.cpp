    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) 
    {
        int n = gas.size();
        int curr=0;
        int ans=0,sum=0;
        for(int i=0;i<n;i++)
        {
            int val = gas[i]-cost[i];
            sum+=val;
            curr+=val;
            if(curr<=0)
            {
                if(curr==0 and i==n-1) continue;
                curr=0;
                ans=i+1;
            }
        }
        if(sum<0) return -1;
        if(ans>=n) return -1;
        return ans;
    }
