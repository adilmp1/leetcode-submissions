int longestOnes(vector<int> &a, int k)
{
    int ans = 0;
    int left = 0;
    int right = 0;
    int n = a.size();
    int zero = 0;
    
    while (right < n)
    {   
        if(!a[right]) zero++;

        while(zero>k)
        {
            if(!a[left]) zero--;
            left++;
        }

        ans = max(ans,right-left+1);
        right++;
    }
    
    return ans;
}
