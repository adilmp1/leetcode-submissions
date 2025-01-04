int helper(string s,char ch)
{
    int n = s.size();
    int left = 0;
    int right=n-1;
    while(s[left]!=ch) left++;
    while(s[right]!=ch) right--;
    left++;
    right--;
    unordered_set<char> st;
    for(int i=left;i<=right and i>=0 and i<n;i++)
    {
        st.insert(s[i]);
    }

    return st.size();

}

int countPalindromicSubsequence(string s)
{
    int ans=0;
    unordered_map<char,int> mp;
    for(char i:s) mp[i]++;
    for(auto pair:mp)
    {
        if(pair.second>=2)
        {
            ans+=helper(s,pair.first);
        }
    }
    return ans;
}
