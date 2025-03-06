    vector<int> deckRevealedIncreasing(vector<int>& a) {
        int n = a.size();
        queue<int> q;
        for(int i=0;i<n;i++) q.push(i);
        sort(a.begin(),a.end());
        vector<int> ans(n,0);
        for(int i=0;i<n;i++)
        {
            ans[q.front()] = a[i];
            q.pop();
            if(!q.empty())
            {
                q.push(q.front());
                q.pop();
            }
        }
        return ans;
    }
