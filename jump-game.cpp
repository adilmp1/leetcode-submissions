    bool canJump(vector<int>& a) 
    {
        int maxReach=0;
        for(int i=0;i<a.size();i++)
        {
            if(maxReach>=i)
            {
                maxReach=max(maxReach,i+a[i]);
            }
        }
        return (maxReach>=a.size()-1);
    }
