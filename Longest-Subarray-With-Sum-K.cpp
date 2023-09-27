#include <map>
int longestSubarrayWithSumK(vector<int> a, long long k)
{
    int n = a.size();
    map<int, int> mp;
    mp[0] = -1;
    int ans = -1;
    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
        if (mp.find(sum - k) != mp.end())
        {
            ans = max(ans, i - mp[sum - k]);
        }
        if (mp.count(sum) == 0)
        {
            mp[sum] = i;
        }
    }
    return ans;
}
