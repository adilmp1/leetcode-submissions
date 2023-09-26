vector<int> spiralOrder(vector<vector<int>> &a)
{
    vector<int> ans;
    int n = a.size();
    int m = a[0].size();
    int top = 0;
    int bottom = n - 1;
    int right = m - 1;
    int left = 0;
    int count = 0;
    while (top <= bottom and left <= right)
    {
        for (int i = left; i <= right; i++)
        {
            if (ans.size() != m * n)
                ans.push_back(a[top][i]);
        }
        top++;
        for (int i = top; i <= bottom; i++)
        {
            if (ans.size() != m * n)
                ans.push_back(a[i][right]);
        }
        right--;
        for (int i = right; i >= left; i--)
        {
            if (ans.size() != m * n)
                ans.push_back(a[bottom][i]);
        }
        bottom--;
        for (int i = bottom; i >= top; i--)
        {
            if (ans.size() != m * n)
                ans.push_back(a[i][left]);
        }
        left++;
    }
    return ans;
}
