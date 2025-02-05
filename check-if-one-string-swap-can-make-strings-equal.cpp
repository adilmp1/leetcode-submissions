    bool areAlmostEqual(string s1, string s2) 
    {
        vector<int> m1(26,0);
        vector<int> m2(26,0);
        int n = s1.size();
        int count=0;
        for(int i=0;i<n;i++) 
        {
            count+=(s1[i]!=s2[i]);
            m1[s1[i]-'a']++;
            m2[s2[i]-'a']++;
        }
        if(m1!=m2) return false;
        return (count==0 or count==2);
    }
