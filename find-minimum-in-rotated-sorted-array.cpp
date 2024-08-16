int findMin(vector<int> &a)
{
    int low = 0;
    int high = a.size()-1;
    int mid;
    if(a.size()==1) return a[0];
    if(a.size()>=2)
    {
        if(a[0]<a[1] and a[0]<a.back()) return a[0];
    }
    while(low<=high)
    {
        mid = (low+high)/2;
        if(mid>0 and a[mid]<a[mid-1])
        {
            return a[mid];
        }
        else if(mid<a.size()-1 and a[mid]>a[mid+1])
        {
            return a[mid+1];
        }
        else if(a[high]>a[mid] and a[low]>a[mid])
        {
            high=mid-1;
        }
        else
        {
            low=mid+1;
        }
    }
    return a[mid];
}
