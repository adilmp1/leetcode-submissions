int maximumSwap(int num)
{
    string s = to_string(num);
    string t = s;
    sort(t.begin(),t.end(),greater<char>());
    bool flag=false;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]!=t[i])
        {
            flag=true;
            char c = t[i];
            for(int j=s.size()-1;j>=0;j--)
            {
                if(s[j]==c)
                {
                    swap(s[i],s[j]);
                }
            }
        }
        if(flag) break;
    }
    long long int ans=0;
    for(char i:s)
    {
        ans*=10;
        ans+=(int)i-'0';
    }
    return ans;
}
