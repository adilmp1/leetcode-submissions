int longestSubarray(vector<int> &a)
{
    vector<int> freq;
    if(a[0]==0) freq.push_back(0);
    int zeroes=0,ones=0;
    for(int i=0;i<a.size();i++)
    {
        if(a[i])
        {
            if(zeroes!=0) freq.push_back(zeroes);
            ones++;
            zeroes=0;
        }
        else 
        {
            if(ones!=0) freq.push_back(ones);
            zeroes++;
            ones=0;
        }
    }
    if(zeroes) freq.push_back(zeroes);
    if(ones) freq.push_back(ones);
    // display(freq);
    int ans=0;
    if(freq.size()==1) return freq[0]-1;
    if(freq.size()%2 == 0) freq.push_back(0);
    for(int i=0;i<freq.size()-2;i+=2) 
    {
        ans = max(ans,freq[i]);
        ans = max(ans,freq[i+2]);
        if(freq[i+1]==1) ans = max(ans,freq[i]+freq[i+2]);
    }
    return ans;
}
