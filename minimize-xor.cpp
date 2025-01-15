int minimizeXor(int num1, int num2)
{
    int n1 = num1;
    int n =0;
    int n2 = num2;
    int cnt=0;
    
    string s1,s2;

    while(n2)
    {
        if(n2%2)
        {
            cnt++;
            s2.push_back('1');
        }
        else 
        {
            s2.push_back('0');
        }
        n2/=2;
    }
    while(n1)
    {
        if(n1%2) s1.push_back('1');
        else s1.push_back('0');
        n1/=2;
    }

    if(s1.size()>s2.size())
    {
        while(s1.size()!=s2.size())
        {
            s2.push_back('0');
        }
    }
    else if(s1.size() < s2.size())
    {
        while(s1.size()!=s2.size())
        {
            s1.push_back('0');
        }
    }

    reverse(s1.begin(),s1.end());
    reverse(s2.begin(),s2.end());

    string s3(s1.size(),'0');

    for(int i=0;i<s1.size() and cnt;i++)
    {
        if(s1[i]=='1')
        {
            s3[i]='1';
            cnt--;
        }
    }

    for(int i=s3.size()-1;i>=0 and cnt;i--)
    {
        if(s3[i]=='0')
        {
            s3[i]='1';
            cnt--;
        }
    }

    int ans=0;
    for(char c:s3)
    {
        ans*=2;
        if(c=='1') ans++;
    }
    return ans;   
}
