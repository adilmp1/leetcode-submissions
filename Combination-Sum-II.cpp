vector<vector<int>> ans;
void helper(int idx,vector<int>& temp,int currCount,int target,int k,int n)
{
    if(target==0 and currCount==k)
    {
        ans.push_back(temp);
        return;
    }
    if(currCount>k)
    {
        return;
    }
    if(target<=0)
    {
        return;
    }
    for(int i=idx;i<=9;i++)
    {
        temp.push_back(i);
        helper(i+1,temp,currCount+1,target-i,k,n);
        temp.pop_back();
    }
}
vector<vector<int>> combinationSum3(int k,int n)
{
    vector<int> temp;
    helper(1,temp,0,n,k,n);
    return ans;
}
