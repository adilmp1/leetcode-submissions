    bool lemonadeChange(vector<int>& a) 
    {
        unordered_map<int,int> mp;
        for(int i=0;i<a.size();i++)
        {
            if(a[i]==5)
            {
                mp[5]++;
            }
            else if(a[i]==10)
            {
                if(mp[5]==0)
                {
                    return false;
                }
                mp[10]++;
                mp[5]--;
            }
            else
            {
                if (mp[5]>=1 and mp[10]>=1)
                {
                    mp[5]--;
                    mp[10]--;
                }
                else if(mp[5]>=3)
                {
                    mp[5]-=3;
                }
                else
                {
                    return false;
                }
            }
        }
        return true;
    }
