vector<vector<int>> ans;
void helper(vector<int> &a, int sum, int index, int target, vector<int> &temp)
{
    if (sum == target)
    {
        ans.push_back(temp);
        return;
    }
    if (sum > target)
    {
        return;
    }
    for (int i = index; i < a.size(); i++)
    {
        sum += a[i];
        temp.push_back(a[i]);
        helper(a, sum, i, target, temp);
        sum -= a[i];
        temp.pop_back();
    }
}
vector<vector<int>> combinationSum(vector<int> &a, int target)
{
    int sum = 0;
    vector<int> temp;
    helper(a, sum, 0, target, temp);
    return ans;
}
