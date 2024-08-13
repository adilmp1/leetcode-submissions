void removeOverlapp(vector<vector<int>> &v)
{
    vector<int> b = v.back();
    v.pop_back();
    vector<int> a = v.back();
    v.pop_back();
    if (b[0] <= a[1])
    {
        if (b[1] >= a[1])
        {
            v.push_back({a[0], b[1]});
        }
        else
        {
            v.push_back({a[0], a[1]});
        }
    }
    else
    {
        v.push_back(a);
        v.push_back(b);
    }
}

vector<vector<int>> insert(vector<vector<int>> &a, vector<int> &b)
{
    vector<vector<int>> ans;
    int idx = 0;
    bool flag = true;
    for (int i = 0; i < a.size(); i++)
    {
        vector<int> &cI = a[i];
        if (flag and b[0] < cI[0])
        {
            flag = !flag;
            ans.push_back(b);
            if (ans.size() >= 2)
                removeOverlapp(ans);
        }
        ans.push_back(cI);
        if (!flag)
            removeOverlapp(ans);
    }
    if (flag)
    {
        ans.push_back(b);
        if (ans.size() >= 2)
            removeOverlapp(ans);
    }
    return ans;
}
