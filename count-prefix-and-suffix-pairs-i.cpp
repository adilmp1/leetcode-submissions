bool helper(string a,string b)
{
    int m = a.size();
    int n = b.size();
    if(b.substr(0,m)==a and b.substr(n-m,m)==a) return true;
    return false;
}

int countPrefixSuffixPairs(vector<string> &words)
{
    int count=0;
    int n = words.size();
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(helper(words[i],words[j]))
            {
                count++;
            }
        }
    }
    return count;
}
