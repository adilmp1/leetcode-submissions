int majorityElement(vector<int> &a)
{
    int n = a.size();
    if (n == 1)
        return a[0];
    sort(a.begin(), a.end());
    int maxi = INT_MIN;
    int ans = -1;
    int count = 1;
    bool flag = true;
    for (int i = 1; i < n; i++)
    {
        if (a[i] == a[i - 1])
        {
            count++;
        }
        else
        {
            if (count != 1)
            {
                if (count > maxi)
                {
                    ans = a[i - 1];
                    maxi = count;
                    count = 1;
                }
            }
        }
    }
    if (count > maxi)
    {
        ans = a[n - 1];
        maxi = count;
    }
    return ans;
}
