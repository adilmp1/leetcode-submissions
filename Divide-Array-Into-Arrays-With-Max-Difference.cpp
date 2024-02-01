vector<vector<int>> divideArray(vector<int>& a, int k) 
    {
        vector<vector<int>> ans;
        vector<vector<int>> mt;
        int n = a.size();
        if(n%3!=0) return mt;
        sort(a.begin(),a.end());  
        for(int i=0;i<n;i+=3)
        {
            vector<int> temp;
            bool v1 = abs(a[i]-a[i+1])>k;
            bool v2 = abs(a[i]-a[i+2])>k;
            bool v3 = abs(a[i+1]-a[i+2])>k;
            if(v1 or v2 or v3) 
                return mt;
            else
            {
                temp.push_back(a[i]);
                temp.push_back(a[i+1]);
                temp.push_back(a[i+2]);
                ans.push_back(temp);
            }
        } 
        return ans;
    }
