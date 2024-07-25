// First submission
bool isValid(int row, int col, int m, int n)
{
    if (row < 0)
        return false;
    if (row >= m)
        return false;
    if (col < 0)
        return false;
    if (col >= n)
        return false;
    return true;
}
vector<int> findDiagonalOrder(vector<vector<int>> &a)
{
    vector<int> ans;
    int m = a.size();
    int n = a[0].size();
    int count=1;
    for (int i = 0; i < n; i++)
    {
        vector<int> temp;
        int row = 0;
        int col = i;
        for (int j = i; j >= 0; j--)
        {
            if(isValid(row,col,m,n))
            {
                temp.push_back(a[row++][col--]);
            }
        }
        if(count%2==0)
        {
            for(int val:temp) ans.push_back(val);
        }
        else
        {
            while(!temp.empty())
            {
                ans.push_back(temp.back());
                temp.pop_back();
            }
        }
        count++;
    }
    if(n%2==1) count=0;
    else count=1;
    for (int i = 1; i < m; i++)
    {
        vector<int> temp;
        int row = i;
        int col = n - 1;
        for (int j = m - i; j >= 0; j--)
        {
            if (isValid(row, col, m, n))
                temp.push_back(a[row++][col--]);
        }
        
        if(count%2==0)
        {
            for(int val:temp) ans.push_back(val);
        }
        else
        {
            while(!temp.empty())
            {
                ans.push_back(temp.back());
                temp.pop_back();
            }
        }
        count++;
    }
    return ans;
}
