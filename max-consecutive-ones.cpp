int findMaxConsecutiveOnes(vector<int> &a)
{
    int n = a.size();
    int ans = INT_MIN;
    int count = 0;
    for (int i = 0; i < n;)
    {
        while (i < n and a[i] == 1)
        {
            count++;
            i++;
        }
        ans = max(ans, count);
        count = 0;
        while (i < n and a[i] == 0)
        {
            i++;
        }
    }
    return ans;
}
