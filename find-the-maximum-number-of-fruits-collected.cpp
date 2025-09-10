int helper(vector<vector<int>> a,int n, bool isOdd)
{
    int half = n / 2;
    vector<vector<int>> a1(n, vector<int>(half, 0));
    int inc = -1;
    int val = half - 1;
    int pre = half;
    if (isOdd)
        pre = half + 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = half - 1; j >= val; j--)
        {
            a1[i][j] = a[i][pre + j];
        }
        if (val == 0)
        {
            if (isOdd)
            {
                val++;
                isOdd = false;
            }
            else
            {
                inc = -inc;
            }
        }
        val += inc;
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < half; j++)
        {
            int v1 = 0, v2 = 0, v3 = 0;
            if (j == 0)
            {
                v1 = a1[i - 1][j];
                if (a1[0].size() > j + 1)
                    v2 = a1[i - 1][j + 1];
            }
            else if (j == half - 1)
            {
                v1 = a1[i - 1][j];
                if (j - 1 >= 0)
                    v3 = a1[i - 1][j - 1];
            }
            else
            {
                v1 = a1[i - 1][j];
                if (a1[0].size() > j + 1)
                    v2 = a1[i - 1][j + 1];
                if (j - 1 >= 0)
                    if (j - 1 >= 0)
                        v3 = a1[i - 1][j - 1];
            }
            a1[i][j] += max({v1, v2, v3});
        }
    }
    return a1[n - 1][half - 1];
}
void transpose(vector<vector<int>>& a, int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            swap(a[i][j],a[j][i]);
        }
    }
}
int maxCollectedFruits(vector<vector<int>> &a)
{
    int n = a.size();
    bool isOdd = (n & 1);
    int ans = 0;

    // guy from top left
    for (int i = 0; i < n; i++)
    {
        ans += a[i][i];
        a[i][i] = 0;
    }

    ans += helper(a,n,isOdd);
    transpose(a,n);
    ans += helper(a,n,isOdd);
    return ans;
}
