int minOperations(vector<int> &nums)
{
    stack<int> s;
    int ans=0;
    for(int n:nums)
    {
        while(!s.empty() and s.top()>n) 
        {
            ans++;
            s.pop(); 
        }
        if(n and (s.empty() or s.top()!=n)) s.push(n);
    }
    return ans+s.size();
}
