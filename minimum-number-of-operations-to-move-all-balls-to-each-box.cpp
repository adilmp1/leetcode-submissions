vector<int> minOperations(string s)
{
    vector<int> ans;
    int n = s.size();
    int total_ones=0;
    int curr=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='1')
        {
            if(i>0)
            {
                curr+=i;
            }
            total_ones++;
        }
    }
    int curr_ones=(int)s[0]-'0';
    ans.push_back(curr);
    for(int i=1;i<n;i++)
    {
        int left = curr_ones;
        int right = total_ones-curr_ones;
        if(s[i]=='1') right--;
        curr+=(left-right);
        if(s[i]=='1')
        {
            curr--;
            curr_ones++;
        }
        ans.push_back(curr);
    }
    return ans;
}
