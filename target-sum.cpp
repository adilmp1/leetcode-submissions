int findTargetSumWaysHelper(vector<int> &a, int target, int idx, vector<vector<int>> &dp, int offset)
{
    if (idx == a.size())
    {
        return target == 0 ? 1 : 0;
    }

    int adjtarget = target + offset;
    if (adjtarget < 0 || adjtarget >= dp[0].size()) return 0; // Bounds check

    if (dp[idx][adjtarget] != -1) return dp[idx][adjtarget];

    int ans = 0;
    ans += findTargetSumWaysHelper(a, target - a[idx], idx + 1, dp, offset);
    ans += findTargetSumWaysHelper(a, target + a[idx], idx + 1, dp, offset);

    return dp[idx][adjtarget] = ans;
}

int findTargetSumWays(vector<int> &a, int target)
{
    int n = a.size();
    int sum = 0;
    for (int i : a) sum += i;

    if (target > sum || target < -sum) return 0;

    int offset = sum;
    vector<vector<int>> dp(n, vector<int>(2 * sum + 1, -1));

    return findTargetSumWaysHelper(a, target, 0, dp, offset);
}
