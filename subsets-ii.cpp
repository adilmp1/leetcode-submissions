vector<vector<int>> v;
void helper(vector<int> &a, int idx, vector<int> temp)
{
    v.push_back(temp);
    for (int i = idx; i < a.size(); i++)
    {
        if (i > idx && a[i] == a[i - 1]) continue; 
        temp.push_back(a[i]);
        helper(a, i + 1, temp);
        temp.pop_back(); 
    }
}

vector<vector<int>> subsetsWithDup(vector<int> &a)
{
    vector<int> temp = {};
    sort(a.begin(),a.end());
    helper(a, 0, temp);
    return v;
}
