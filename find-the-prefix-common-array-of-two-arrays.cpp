    vector<int> findThePrefixCommonArray(vector<int>& a, vector<int>& b) 
    {
        int n = a.size();
        vector<int> freq(n+1,0);
        vector<int> ans;
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            freq[a[i]]++;
            freq[b[i]]++;
            if(freq[a[i]]==2) cnt++;
            if(freq[b[i]]==2 and a[i]!=b[i]) cnt++;
            ans.push_back(cnt);
        }
        return ans;
    }
