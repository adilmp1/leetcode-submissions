int totalFruit(vector<int> &a)
{
    int n = a.size();
    unordered_map<int,int> mp;
    int left=0;
    int right=0;
    int ans = 0;
    while(right<n)
    {
        int value = a[right];
        mp[value]++;

        while(left<right and mp.size()>2)
        {
            int value = a[left++];  
            mp[value]--;
            if(mp[value]==0) mp.erase(value);
        }

        ans = max(ans,right-left+1);
        right++;
    }
    return ans;
}
