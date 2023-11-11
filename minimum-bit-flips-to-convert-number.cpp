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
