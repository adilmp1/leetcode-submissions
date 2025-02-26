    int maxAbsoluteSum(vector<int>& nums) {
        long minPrefixSum = 0;
        long maxPrefixSum = 0;
        long sum=0;
        for(auto i:nums)
        {
            sum+=i;
            minPrefixSum = min(minPrefixSum,sum);
            maxPrefixSum = max(maxPrefixSum,sum);
        }
        return abs(maxPrefixSum-minPrefixSum);
    }
