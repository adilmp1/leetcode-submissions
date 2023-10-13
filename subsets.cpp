vector<vector<int>> ans;
void helper(vector<int> a, int k, vector<int> &temp)
{
    if (temp.size() == a.size())
    {
        ans.push_back(temp);
        return;
    }
    else if (temp.size() < a.size())
    {
        if (temp.size())
        {
            ans.push_back(temp);
        }
    }
    for (int i = k; i < a.size(); i++)
    {
        temp.push_back(a[i]);
        helper(a, i + 1, temp);
        temp.pop_back();
    }
}
vector<vector<int>> subsets(vector<int>& a) 
{
    vector<int> temp;
    ans.push_back({});
    helper(a,0,temp);
    sort(ans.begin(),ans.end());
    return ans;
}
