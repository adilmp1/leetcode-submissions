int binarysearch(vector<int> a, int low, int high, int k)
{
    int f = low;
    int l = high;
    int m;
    while (f <= l)
    {
        m = (f + l) / 2;
        if (a[m] == k)
        {
            return m;
        }
        else if (a[m] > k)
        {
            l = m - 1;
        }
        else
        {
            f = m + 1;
        }
    }
    return -1;
}
vector<int> searchRange(vector<int> a, int k)
{
    vector<int> ans;
    int n = a.size();
    int i = n - 1;
    int right = -1;
    int x = binarysearch(a, 0, n - 1, k);
    int temp = x;
    while (x != -1)
    {
        right = x;
        x = binarysearch(a, 0, i, k);
        i = x - 1;
    }
    ans.push_back(right);
    x = temp;
    i = 0;
    while (x != -1)
    {
        right = x;
        x = binarysearch(a, i, n - 1, k);
        i = x + 1;
    }
    ans.push_back(right);
    return ans;
}
