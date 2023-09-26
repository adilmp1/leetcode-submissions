int subarraySum(vector<int> &a, int k)
{
    int n = a.size();
    unordered_map<int, int> mp;
    mp[0] = 1;
    int count = 0, sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
        count += mp[sum - k];
        mp[sum]++;
    }
    return count;
}
