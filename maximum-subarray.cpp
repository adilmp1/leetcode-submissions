int maxSubArray(vector<int> &a)
{
    int n = a.size();
    int sum = 0;
    int ans = a[0];
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
        ans = max(ans, sum);
        if (sum < 0)
        {
            sum = 0;
        }
    }
    return ans;
}
