bool isValid(int m, int n, int x, int y)
{
    return (x >= 0 and x < m and y >= 0 and y < n);
}

vector<vector<int>> spiralMatrixIII(int m, int n, int x, int y)
{
    if (m==1 and n==1) return {{0,0}};
    int count = m * n;
    int copy = count;
    vector<vector<int>> ans;
    ans.push_back({x, y});

    bool flag = true;
    int time = 1;

    while (true)
    {
        int k = time;
        int add = 1;
        if(!flag) add=-1;
        while (k--)
        {
            y+=add;
            if (isValid(m, n, x, y))
            {
                ans.push_back({x, y});
                if (ans.size() == copy)
                    return ans;
                count--;
            }
        }
        k = time;
        while (k--)
        {
            x+=add;
            if (isValid(m, n, x, y))
            {
                ans.push_back({x, y});
                if (ans.size() == copy)
                    return ans;
                count--;
            }
        }
        flag = !flag;
        time++;
    }
    return ans;
}
