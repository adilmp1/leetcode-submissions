// My code using memoization-recursion
    bool canPartitionHelper(vector<int> a,int n,long long target,long long sum,int curr,vector<vector<int>>& dp)
    {
        if (sum == target) return dp[curr][sum] = true;
        if (curr >= n || sum > target) return dp[curr][sum] = false;
        if (dp[curr][sum] != -1) return dp[curr][sum];
        return dp[curr][sum]=(canPartitionHelper(a,n,target,sum+a[curr],curr+1,dp) or canPartitionHelper(a,n,target,sum,curr+1,dp));

    }
    bool canPartition(vector<int>& a) 
    {
        int n = a.size();
        long long target=0;
        for(int i:a)
        {
            target+=i;
        }
        if(target%2==1) return false;
        vector<vector<int>> dp(n+1,vector<int>(target+1,-1));
        target/=2;

        return canPartitionHelper(a,a.size(),target,0,0,dp);
    }
