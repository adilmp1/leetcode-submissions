    int searchInsert(vector<int>& a, int target) 
    {
        int n = a.size();
        int low = 0;
        int high = a.size()-1;
        int ans=-1;
        while(low<=high)
        {
            int mid = (low+high)/2;
            ans=mid;
            if(a[mid]==target) return mid;
            else if(a[mid]>target) high=mid-1;
            else low=mid+1;
        }
        if(ans>=0 and ans<n-1 and a[ans]<target and a[ans+1]>target) return ans+1;
        if(ans>=0 and a[ans]<target) return ans+1;
        return ans;
    }
