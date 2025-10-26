int maxDistinctElements(vector<int> &a, int k)
{
    int ans=0;
    sort(a.begin(),a.end());
    int prevMax = INT_MIN;
    for(int num:a)
    {
        int lowerBound = num-k;
        int upperBound = num+k;

        if(prevMax < lowerBound)
        {
            prevMax = lowerBound;
            ans++;
        }
        else if(prevMax < upperBound)
        {
            prevMax++;
            ans++;
        }
    }
    return ans;
}
