int minOperations(vector<int>& a, int x) 
{
    int n=a.size();
    int sum=0;
    for(int i:a) sum+=i;
    if(x==sum) return n;
    int target = sum-x;
    int maxLength=0;
    unordered_map<int,int> mp;
    mp[0]=0;
    sum=0;
    bool flag=false;
    for(int i=0;i<n;i++)
    {
        sum+=a[i];
        if(mp.count(sum-target))
        {
            flag=true;
            maxLength = max(maxLength,i-mp[sum-target]+1);
        }
        mp[sum]=i+1;
    }
    if(!flag) return -1;
    return (n-maxLength);
}
