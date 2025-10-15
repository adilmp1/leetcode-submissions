bool helper(int left,int right, int mid, vector<int>& a,int cas)
{
    int leftNeighbor = INT_MIN;
    int rightNeighbor = INT_MIN;
    if(mid>=1) leftNeighbor = a[mid-1];
    if(mid<a.size()-1) rightNeighbor = a[mid+1];
    // cas = 1 for checking peak
    if(cas==1) return (a[mid]>leftNeighbor and a[mid]>rightNeighbor);
    return (a[mid]<rightNeighbor);

}

int findPeakElement(vector<int> &a)
{
    int left = 0;
    int right = a.size()-1;

    while(left<=right)
    {
        int mid = (left+right)/2;
        if(helper(left,right,mid,a,1))
        {
            return mid;
        }
        else if(helper(left,right,mid,a,2))
        {
            left = mid+1;
        }
        else
        {
            right = mid-1;
        }
    }
    return 0; 
}
