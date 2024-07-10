    int maxArea(vector<int>& a) 
    {
        int left=0;
        int right=a.size()-1;
        int ans=INT_MIN;
        while(left<right)
        {
            int val = min(a[left],a[right]);
            int x =val*(right-left);
            ans=max(ans,x);
            if(a[left]==val)
            {
                left++;
            }
            else
            {
                right--;
            }
        }
        return ans;
    }
