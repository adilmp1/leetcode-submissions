bool isVowel(char c)
{
    return (c=='a' or c=='e' or c=='i' or c=='o' or c=='u');
}

long long helper(string a, int k)
{
    unordered_map<int, int> mp;
    long long ans = 0;
    int idx = 0;
    int n = a.size();
    int cons = 0;
    int left = 0;
    int right = 0;

    while(right<n)
    {
        if(mp.size()==5 and cons>=k)  
        {
            while(mp.size()==5 and cons>=k)
            {
                char ch = a[left];  
                left++;
                if(isVowel(ch))
                {
                    mp[ch]--;
                    if(mp[ch]==0) mp.erase(ch);
                }
                else
                {
                    cons--;
                }
                if(mp.size()==5 and cons>=k) ans+=n-right+1;
            }
        }
        char ch = a[right];
        if(isVowel(ch)) mp[ch]++;
        else cons++;
        if(mp.size()==5 and cons>=k) ans+=n-right;
        right++;
    }
    if(mp.size()==5 and cons>=k)  
    {
        while(mp.size()==5 and cons>=k)
        {
            char ch = a[left];  
            left++;
            if(isVowel(ch))
            {
                mp[ch]--;
                if(mp[ch]==0) mp.erase(ch);
            }
            else
            {
                cons--;
            }
            if(mp.size()==5 and cons>=k) ans+=n-right+1;
        }
    }
    return ans;
}

long long countOfSubstrings(string a, int k) 
{
    return helper(a,k)-helper(a,k+1);
}
