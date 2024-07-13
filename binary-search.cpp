    int search(vector<int>& a, int target) {
        int low=0;
        int high=a.size()-1;
        while(low<=high)
        {
            int mid = (low+high)>>1;
            if(a[mid]==target)
            {
                return mid;
            }
            else if(a[mid]>target)
            {
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return -1;
    }
