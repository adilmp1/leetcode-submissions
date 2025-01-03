int mincostTickets(vector<int> &a, vector<int> &b)
{
    int n = a.size();
    vector<int> dp(n + 1, INT_MAX);
    int day = b[0];
    int week = b[1];
    int month = b[2];

    dp[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        dp[i] = dp[i - 1] + day;

        for (int j = i - 1; j >= 0 && a[i - 1] - a[j] < 7; j--)
        {
            dp[i] = min(dp[i], dp[j] + week);
        }

        for (int j = i - 1; j >= 0 && a[i - 1] - a[j] < 30; j--)
        {
            dp[i] = min(dp[i], dp[j] + month);
        }
    }
    return dp[n];
}
