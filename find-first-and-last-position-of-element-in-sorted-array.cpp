// solution 1
int binarysearch(vector<int> a, int low, int high, int k)
{
    int f = low;
    int l = high;
    int m;
    while (f <= l)
    {
        m = (f + l) / 2;
        if (a[m] == k)
        {
            return m;
        }
        else if (a[m] > k)
        {
            l = m - 1;
        }
        else
        {
            f = m + 1;
        }
    }
    return -1;
}
vector<int> searchRange(vector<int> a, int k)
{
    vector<int> ans;
    int n = a.size();
    int i = n - 1;
    int right = -1;
    int x = binarysearch(a, 0, n - 1, k);
    int temp = x;
    while (x != -1)
    {
        right = x;
        x = binarysearch(a, 0, i, k);
        i = x - 1;
    }
    ans.push_back(right);
    x = temp;
    i = 0;
    while (x != -1)
    {
        right = x;
        x = binarysearch(a, i, n - 1, k);
        i = x + 1;
    }
    ans.push_back(right);
    return ans;
}


// solution 2
int leftBinarySearch(vector<int> a, int low, int high, int k)
{
    int f = low;
    int l = high;
    int m;
    while (f <= l)
    {
        m = (f + l) / 2;
        if (a[m] == k)
        {
            int x = leftBinarySearch(a,0,m-1,k);
            if(x!=-1)
            {
                return min(m,x);
            }
            else
            {
                return m;
            }
            
        }
        else if (a[m] > k)
        {
            l = m - 1;
        }
        else
        {
            f = m + 1;
        }
    }
    return -1;
}
int rightBinarySearch(vector<int> a, int low, int high, int k)
{
    int f = low;
    int l = high;
    int m;
    while (f <= l)
    {
        m = (f + l) / 2;
        if (a[m] == k)
        {
            int x = rightBinarySearch(a,m+1,a.size()-1,k);
            if(x!=-1)
            {
                return max(m,x);
            }
            else
            {
                return m;
            }
            
        }
        else if (a[m] > k)
        {
            l = m - 1;
        }
        else
        {
            f = m + 1;
        }
    }
    return -1;
}
vector<int> searchRange(vector<int> a, int k)
{
    vector<int> ans;
    int n = a.size();
    int i = n - 1;
    int left = leftBinarySearch(a,0,n-1,k);
    int right = rightBinarySearch(a,0,n-1,k);
    return {left,right};
}
