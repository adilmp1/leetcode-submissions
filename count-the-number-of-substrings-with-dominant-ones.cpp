int numberOfSubstrings(string s)
{
    int n = s.size(), count=0;
    vector<int> prefixOnes(s.size(),0);
    for(int i=0;i<s.size();i++)
    {
        count+=(s[i]=='1');
        prefixOnes[i]=count;
    }
    int ans=0;

    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            int oneCount = (i) ? prefixOnes[j]-prefixOnes[i-1] : prefixOnes[j]; 
            int zeroCount = (j-i+1)-oneCount;

            if(zeroCount*zeroCount > oneCount)
            {
                int k = zeroCount*zeroCount-oneCount;
                j+=k-1;
            }
            else if (zeroCount*zeroCount == oneCount)
            {
                ans++;
            }
            else 
            {
                ans++;
                int k = sqrt(oneCount)-zeroCount;
                if(j+k>=n) 
                {
                    ans+=(n-j-1);
                    break;
                }
                ans+=k;
                j += k;
            }
        }
    }

    return ans;
}
