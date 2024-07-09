    int search(vector<int>& a, int target) 
    {
        int low = 0;
        int high = a.size()-1;
        while(low<=high)
        {
            int mid = (low+high)/2;
            if(a[mid]==target)
            {
                return mid;
            }
            else if(mid>0 and a[low]<=a[mid-1])
            {
                if(mid>low and target>=a[low] and target<=a[mid-1])
                {
                    high=mid-1;
                }
                else
                {
                    low=mid+1;
                }
            }
            else
            {
                if(mid<a.size()-1 and target>=a[mid+1] and target<=a[high])
                {
                    low=mid+1;
                }
                else
                {
                    high=mid-1;
                }
            }
        }
        return -1;
    }
