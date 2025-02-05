vector<vector<int>> fourSum(vector<int> &a, int target)
{
    int n = a.size();
    sort(a.begin(),a.end());
    int diff = INT_MAX;
    vector<vector<int>> ans;
    for(int i=0;i<n;i++)
    {
        if(i > 0 and a[i] == a[i - 1]) continue;
        for(int j=i+1;j<n;j++)
        {
            if(j>(i+1) and a[j] == a[j - 1]) continue;
            int left = j+1;
            int right = n-1;
            while(left<right)
            {
                long long sum = a[i];
                sum+=a[j];
                sum+=a[left];
                sum+=a[right];
                int low = a[left];
                int high = a[right];
                if(sum==target)
                {
                    ans.push_back({a[i],a[j],a[left],a[right]});
                    left++;
                    right--;
                    while(left<right and a[left]==low) left++;
                    while(left<right and a[right]==high) right--;
                }
                else if(sum>target) right--;
                else left++;
            }
        }
    }
    return ans;
}
