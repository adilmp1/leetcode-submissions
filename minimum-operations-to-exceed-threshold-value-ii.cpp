    int minOperations(vector<int>& a, int k) 
    {
        priority_queue<long long,vector<long long>,greater<long long>> pq;
        for(int i:a) pq.push(i);
        int ans=0;
        while(pq.top()<k)
        {
            long long x = pq.top();
            pq.pop();
            long long y = pq.top();
            pq.pop();
            long long val = x;
            val*=2;
            val+=y;
            pq.push(val);
            ans++;
        }
        return ans;
    }
