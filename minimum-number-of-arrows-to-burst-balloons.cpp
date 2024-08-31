static bool comparator(const vector<int> &a, const vector<int> &b)
{
    return a[1] < b[1];
}
int findMinArrowShots(vector<vector<int>> &a)
{
    sort(a.begin(), a.end(), comparator);
    int currEnd = a[0][1];
    int ans = 1;
    for (int i = 1; i < a.size(); i++)
    {
        if (currEnd>=a[i][0] and currEnd <= a[i][1]) continue;
        ans++;
        currEnd = a[i][1];
    }
    return ans;
}
