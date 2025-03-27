    int minOperations(vector<vector<int>>& a, int x) {
        if (a.size() == 1 and a[0].size()==1)
            return 0;
        int mod = a[0][0] % x;
        int m = a.size();
        int n = a[0].size();
        vector<int> b;
        int idx = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                b.push_back(a[i][j]);
                if ((a[i][j] % x) != mod) {
                    return -1;
                }
            }
        }
        sort(b.begin(), b.end());
        int mid = b.size()/2;

        int ans=0;

        for(int i=0;i<b.size();i++) ans+=abs(b[i]-b[mid])/x;
        return ans;
    }
