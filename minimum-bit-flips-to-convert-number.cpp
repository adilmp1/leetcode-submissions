// new code
int minBitFlips(int a, int b)
{
    int count=0;
    for(int i=0;i<32;i++)
    {
        count+=(a%2 != b%2);
        a/=2;
        b/=2;
    }
    return count;
}

    int minBitFlips(int start, int goal) {
        int ans=0;
        while(start or goal)
        {
            if(start%2 != goal%2)
            {
                ans++;
            }
            start/=2;
            goal/=2;
        }
        return ans;
    }
