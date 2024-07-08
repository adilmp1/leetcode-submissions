    vector<vector<int>> threeSum(vector<int>& a) 
    {
        unordered_map<int,int> mp;
        unordered_map<int,int> mp2;
        vector<vector<int>> ans;
        sort(a.begin(),a.end());
        int n=a.size();
        for(int idx=0;idx<a.size();idx++)
        {
            if(mp.find(a[idx])!=mp.end()) continue;
            mp[a[idx]]=1;
            vector<int> temp(3,0);
            int left=idx+1;
            int right=n-1;
            while(left<right)
            {
                if(mp2.find(a[left])!=mp2.end()) 
                {
                    left++;
                    continue;
                }
                int sum = a[idx]+a[left]+a[right];
                if(sum==0)
                {
                    mp2[a[left]]=1;
                    temp[0]=a[idx];
                    temp[1]=a[left];
                    temp[2]=a[right];
                    ans.push_back(temp);
                    left++;
                    right--;
                }
                else if(sum<0)
                {
                    left++;
                }
                else
                {
                    right--;
                }
            }
            mp2.clear();
        }
        mp.clear();
        return ans;
    }
