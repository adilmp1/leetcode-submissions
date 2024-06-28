// First Approach 
    vector<int> partitionLabels(string s) 
    {
        unordered_map<char,int> freq;
        unordered_set<char> st;
        for(char i:s)
        {
            freq[i]++;
        }
        vector<int> ans;
        int length=0;
        unordered_map<int,int> mp;
        for(int i=0;i<s.size();i++)
        {
            mp[s[i]]++;
            st.insert(s[i]);
            length++;
            bool flag=true;
            for(char c:st)
            {
                if(mp[c]!=freq[c]) 
                {
                    flag=false;
                    break;
                }
            }
            if(flag)
            {
                ans.push_back(length);
                length=0;
                mp.clear();
                st.clear();
            }
        }
        return ans;
    }

// Optimized
    vector<int> partitionLabels(string s) 
    {
        unordered_map<char,int> last;
        for(int i=0;i<s.size();i++)
        {
            last[s[i]]=i;
        }
        vector<int> ans;
        int length=0;
        int lastIndex=INT_MIN;
        for(int i=0;i<s.size();i++)
        {
            lastIndex = max(last[s[i]],lastIndex);
            length++;
            if(i==lastIndex)
            {
                ans.push_back(length);
                lastIndex=INT_MIN;
                length=0;
            }
        }
        return ans;
    }
