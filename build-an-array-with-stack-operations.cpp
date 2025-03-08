    vector<string> buildArray(vector<int>& a, int n) 
    {
        vector<string> ans;
        string push = "Push";
        string pop = "Pop";    
        stack<int> s;
        int idx=0;
        int val =1;
        while(idx<a.size())
        {
            s.push(val);
            ans.push_back(push);
            if(!s.empty() and s.top()!=a[idx])
            {
                s.pop();
                ans.push_back(pop);
            }
            else
            {
                idx++;
            }
            val++;
        }
        return ans;
    }
