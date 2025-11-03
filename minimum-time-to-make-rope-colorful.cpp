int minCost(string colors, vector<int> &neededTime)
{
    int n = neededTime.size();
    int longestTime = 0;
    int ans=0;
    int curr=0;
    bool flag=false;
    for(int i=0;i<n;i++)
    {
        int idx=i;
        while(idx<n-1 and colors[idx]==colors[idx+1])
        {
            flag=true;
            curr+=neededTime[idx];
            longestTime = max(longestTime,neededTime[idx]);
            idx++;
        }
        if(flag)
        {
            curr+=neededTime[idx];
            longestTime = max(longestTime,neededTime[idx]);
            flag=false;
            curr-=longestTime;
            ans+=curr;
            curr=0;
            longestTime=0;
        }
        i=idx;
    }
    return ans;
}
