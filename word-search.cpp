bool existHelper(vector<vector<char>> &a, string &s, int x, int y, int curr, vector<vector<bool>> &mp)
{
    if (curr >= s.size())
    {
        return true;
    }
    if (x < 0 or y < 0 or x >= a.size() or y >= a[0].size() or a[x][y] != s[curr] or mp[x][y])
    {
        return false;
    }
    mp[x][y] = true;
    bool result = false;
    result = (existHelper(a, s, x - 1, y, curr + 1, mp) or
              existHelper(a, s, x + 1, y, curr + 1, mp) or
              existHelper(a, s, x, y - 1, curr + 1, mp) or
              existHelper(a, s, x, y + 1, curr + 1, mp));
    mp[x][y] = false;
    return result;
}

bool exist(vector<vector<char>> &a, string &s)
{
    int m = a.size();
    int n = a[0].size();
    vector<vector<bool>> mp(m, vector<bool>(n, false));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] == s[0] and existHelper(a, s, i, j, 0, mp))
            {
                return true;
            }
        }
    }
    return false;
}
