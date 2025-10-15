int maxIncreasingSubarrays(vector<int> &a)
{
    // 2, 5, 7, 8, 9, 2, 3, 4, 3, 1
    vector<int> temp;
    int cnt=1;
    for(int i=1;i<a.size();i++)
    {
        if(a[i]>a[i-1])
        {
            cnt++;
        }
        else
        {
            temp.push_back(cnt);
            cnt=1;
        }
    }
    temp.push_back(cnt);
    // display(temp);
    int ans=temp[0]/2;
    for(int i=0;i<temp.size()-1;i++)
    {
        ans = max(ans,min(temp[i],temp[i+1]));
        ans = max(ans,temp[i]/2);
        ans = max(ans,temp[i+1]/2);
    }    
    return ans;
}
