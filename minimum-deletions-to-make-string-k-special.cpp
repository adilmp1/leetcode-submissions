int minimumDeletions(string word, int k)
{
    vector<int> freq(26,0);
    for(auto ch:word) freq[ch-'a']++;
    vector<int> a;
    for(auto i:freq) if(i) a.push_back(i);
    int ans = INT_MAX;
    for(int i=0;i<a.size();i++)
    {
        int deletions=0;
        int base = a[i];
        for(int j=0;j<a.size();j++)
        {
            if(a[j]<base) deletions+=a[j];
            else if(a[j]>base+k) deletions+=(a[j]-base-k);
        }
        ans = min(ans,deletions);
    }
    return (ans==INT_MAX)?0:ans;
}
