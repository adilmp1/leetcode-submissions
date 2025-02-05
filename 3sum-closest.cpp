int threeSumClosest(vector<int> &a, int target)
{
    int n = a.size();
    sort(a.begin(),a.end());
    int diff = INT_MAX;
    int ans = 0;
    for(int i=0;i<n-2;i++)
    {
        int left = i+1;
        int right = n-1;
        while(left<right)
        {
            int sum = a[i]+a[left]+a[right];
            int curr_diff = abs(target-sum);
            if(curr_diff<diff) 
            {
                diff = curr_diff;
                ans = sum;
            }
            else if(curr_diff==0)
            {
                return sum;
            }
            else if(sum>target)
            {
                right--;
            }
            else
            {
                left++;
            }
        }
    }
    return ans;
}
