    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<int> ans(3, INT_MIN);
        for (vector<int> a : triplets) 
        {
            int v1 = max(a[0], ans[0]);
            int v2 = max(a[1], ans[1]);
            int v3 = max(a[2], ans[2]);
            if (v1 <= target[0] and v2 <= target[1] and v3 <= target[2]) {
                ans[0] = v1;
                ans[1] = v2;
                ans[2] = v3;
            }
        }
        for (int i = 0; i < 3; i++) 
        {
            if (target[i] != ans[i])
                return false;
        }
        return true;
    }
